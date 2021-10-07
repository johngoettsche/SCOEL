/*
 * tpdunix.c: Unix discipline for libtp.
 *      (c) Copyright 2000 by Steve Lumos.  All rights reserved.
 */

#define _UNIXDISC_C_

#include "config.h"
#include "tp.h"
#include "util.h"
#include "tpdunix.h"

#ifdef STDC_HEADERS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#endif

#ifdef HAVE_ERRNO_H
#include <errno.h>
#endif

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#ifdef HAVE_NETDB_H
#include <netdb.h>
#endif

#ifdef HAVE_STRINGS_H
#include <strings.h>    /* For bzero(3) on Solaris */
#endif

#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif

#ifdef HAVE_SYS_SOCKET_H
#include <sys/socket.h>
#endif

#ifdef HAVE_NETINET_IN_H
#include <netinet/in.h>
#endif

#ifdef HAVE_ARPA_INET_H
#include <arpa/inet.h>  /* For inet_pton(3) */
#endif

#define MAX_NAME_LOOKUPS 3
#ifndef MAXADDRS
# define MAXADDRS 35
#endif

int unixconnect(char* host, u_short port, Tpdisc_t* tpdisc)
{
  Tpunixdisc_t* disc = (Tpunixdisc_t*)tpdisc;

  struct in_addr inaddrs[MAXADDRS + 1];
  struct sockaddr_in servaddr;
  int i;

  /* Convert IP address or lookup hostname */
  bzero(inaddrs, sizeof(inaddrs));
  if (inet_pton(AF_INET, host, inaddrs) <= 0) {
    int tries = 1;
    while (tries <= MAX_NAME_LOOKUPS) {
      struct hostent *hep;
      hep = gethostbyname(host);
      if (hep == NULL) {
	int action = tpdisc->exceptf(TP_EHOST, NULL, tpdisc);
	if (action > 0) {
	  continue;
	}
	else {
	  return (-1);
	}
      }
      
      memcpy(inaddrs, *(hep->h_addr_list), MAXADDRS);
      break;
    }
  }

  while (1) {
    if ((disc->fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
      if (tpdisc->exceptf(TP_ESOCKET, NULL, tpdisc) > 0) {
	continue;
      }
      else {
	return (-1);
      }
    }
    else {
      break;
    }
  }

  /* Try all addresses before giving up */
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(port);
  
  for (i=0; inaddrs[i].s_addr != 0; i++) {
    servaddr.sin_addr = inaddrs[i];
    if (connect(disc->fd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
      if (tpdisc->exceptf(TP_ECONNECT, NULL, tpdisc) >= 0) {
	continue;
      }
      else {
	return (-1);
      }
    }
    else {
      return 1;
    }
  }

  /* If we get here, it's an error */
  tpdisc->exceptf(TP_ECONNECT, NULL, tpdisc);
  return (-1);
}

int unixclose(Tpdisc_t* tpdisc)
{
   close(((Tpunixdisc_t*)tpdisc)->fd);
   return 1;
}

void *unixmem(size_t n, Tpdisc_t* tpdisc)
{
  void *ret;

  if (n < 1) {
    return NULL;
  }

  ret = malloc(n);
  if (ret == NULL) {
    (void)tpdisc->exceptf(TP_EMEM, NULL, tpdisc);
    return NULL;
  }

  return (ret);
}

int unixfree(void *p, Tpdisc_t* tpdisc)
{
  free(p);
  return 1;
}

Tpdisc_t* unixnewdisc(Tpdisc_t* tpdisc)
{
  Tpunixdisc_t* newdisc = tpdisc->memf(sizeof(Tpunixdisc_t), tpdisc);

  if (newdisc == NULL) {
    return NULL;
  }
  memcpy(newdisc, tpdisc, sizeof(Tpunixdisc_t));
  return (Tpdisc_t*)newdisc;
}

#ifdef WIN32
int unixexcept(int type, void *obj, Tpdisc_t* tpdisc)
{
  switch(type) {
    case TP_ECONNECT:
      switch (WSAGetLastError()) {
	case EADDRNOTAVAIL:
	case ECONNREFUSED:
	case ENETUNREACH:
	case EADDRINUSE:
	  return TP_RETURNERROR;
	default:
	  return TP_RETURNERROR;
      }

    case TP_EHOST:
      if (WSAGetLastError() == TRY_AGAIN) {
	return TP_TRYAGAIN;
      }
      else {
	return TP_RETURNERROR;
      }

    case TP_EMEM:
      return TP_RETURNERROR;

    case TP_EREAD: 
      if (WSAGetLastError() == EINTR) {
	return TP_TRYAGAIN;
      }
      else {
	ssize_t nread = (*(ssize_t*)obj);
	if (nread == 0) { /* EOF */
	  return TP_DEFAULT;
	}
	else {
	  return TP_RETURNERROR;
	}
      }

    case TP_ESOCKET:
      /* In theory, it may be possible to correct some errors
	 (e.g. ENOBUFS) and return TP_TRYAGAIN. */
      return TP_RETURNERROR;
      
    case TP_EWRITE:
      if (WSAGetLastError() == EINTR) {
	return TP_TRYAGAIN;
      }
      else {
	return TP_RETURNERROR;
      }

    default:
      return TP_RETURNERROR;
  }
}
#else
int unixexcept(int type, void *obj, Tpdisc_t* tpdisc)
{
  switch(type) {
    case TP_ECONNECT:
      switch (errno) {
	case EADDRNOTAVAIL:
	case ECONNREFUSED:
	case ENETUNREACH:
	case EADDRINUSE:
	  return TP_RETURNERROR;
	default:
	  return TP_RETURNERROR;
      }

    case TP_EHOST:
      if (h_errno == TRY_AGAIN) {
	return TP_TRYAGAIN;
      }
      else {
	return TP_RETURNERROR;
      }

    case TP_EMEM:
      return TP_RETURNERROR;

    case TP_EREAD: 
      if (errno == EINTR) {
	return TP_TRYAGAIN;
      }
      else {
	ssize_t nread = (*(ssize_t*)obj);
	if (nread == 0) { /* EOF */
	  return TP_DEFAULT;
	}
	else {
	  return TP_RETURNERROR;
	}
      }

    case TP_ESOCKET:
      /* In theory, it may be possible to correct some errors
	 (e.g. ENOBUFS) and return TP_TRYAGAIN. */
      return TP_RETURNERROR;
      
    case TP_EWRITE:
      if (errno == EINTR) {
	return TP_TRYAGAIN;
      }
      else {
	return TP_RETURNERROR;
      }

    default:
      return TP_RETURNERROR;
  }
}
#endif

/* Similar to readn() from [RS98] */
ssize_t unixread(void* buf, size_t n, Tpdisc_t* tpdisc)
{
  Tpunixdisc_t* disc = (Tpunixdisc_t*)tpdisc;

  size_t  nleft;
  ssize_t nread;
  char*   ptr = buf;

  nleft = n;
  while (nleft > 0) {
    if ((nread = recv(disc->fd, ptr, nleft, 0)) <= 0) {
      int action = tpdisc->exceptf(TP_EREAD, &nread, tpdisc);
      if (action > 0) {
	nread = 0;
	continue;
      }
      else if (action == 0 && nread >= 0) {
	break;
      }
      else {
	return (-1);
      }
    }

    nleft -= nread;
    ptr += nread;
  }
  return (n - nleft);
}

/* Similar to readline() from [RS98] */
ssize_t unixreadln(void* buf, size_t maxlen, Tpdisc_t* tpdisc)
{
  Tpunixdisc_t* disc = (Tpunixdisc_t*)tpdisc;

  ssize_t n, rc;
  char    c;
  char*   ptr = buf;

  for (n=1; n<maxlen; n++) {
  again:
    if ((rc = recv(disc->fd, &c, 1, 0)) == 1) {
      *ptr++ = c;
      if (c == '\n') {
	break;
      }
    }
    else {
      int action = tpdisc->exceptf(TP_EREAD, &rc, tpdisc);
      switch (action)
      {
	case TP_TRYAGAIN: goto again;
	case TP_DEFAULT:
	  if (rc == 0 && n > 1 ){
	    *ptr = '\0';
	    return n-1;   /* no \n in this case */
	  }	  
	  return 0;
	case TP_RETURNERROR:
	default:          return -1;
      }
#if 0
      if (action TP_TRYAGAIN) {
	goto again;
      }
      else if (action == 0) {
	if (rc == 0) {  /* No data read */
	  return (0);
	}
	else {         /* Some data read before error */
	  break;
	}
      }
      else {
	return (-1);
      }
#endif
    }
  }

  *ptr = '\0';  /* Null terminate */
  return (n);
}

/* Similar to writen() from [RS98] */
ssize_t unixwrite(void* buf, size_t n, Tpdisc_t* tpdisc)
{
  Tpunixdisc_t* disc = (Tpunixdisc_t*)tpdisc;

  size_t nleft;
  ssize_t nwritten;
  const char* cp = buf;

  nleft = n;
  nwritten = 0;
  while(nleft > 0) {
    nwritten = send(disc->fd, cp, nleft, 0);
    if (nwritten <= 0) {
      int action = tpdisc->exceptf(TP_EWRITE, NULL, tpdisc);
      if (action <= 0) {
	return (-1);
      }
      else {
	nwritten = 0;
	continue;
      }
    }

    nleft -= nwritten;
    cp += nwritten;
  }

  return nwritten;
}

/* The Unix discipline */
static Tpunixdisc_t _tpdunix = 
{ { unixconnect, unixclose, unixread, unixreadln, 
    unixwrite, unixmem, unixfree, unixexcept, unixnewdisc, 0 }, 0 };

Tpdisc_t* TpdUnix = (Tpdisc_t *)&_tpdunix;
  
int tp_fileno(Tp_t *t)
{
   int fd = ((Tpunixdisc_t *)t->disc)->fd;
   return fd;
}
