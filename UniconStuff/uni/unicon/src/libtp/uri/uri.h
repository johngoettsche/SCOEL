/**********************************************************************\
* uri.h: Parse a URL.                                                  *
* -------------------------------------------------------------------- *
*   (c) Copyright 1999-2000 by Steve Lumos.  All rights reserved.      *
\**********************************************************************/

#ifndef __URI_H__
#define __URI_H__

enum URIERR {
  URI_SUCCESS = 0,     /* URI was parsed correctly */
  URI_OK = 0,          /* Alias for URI_SUCCESS */
  URI_EMALFORMED,      /* Malformed URI */
  URI_ENOUSER,         /* Username required but not present */
  URI_EUNKNOWNSCHEME,  /* Don't have a parser for this scheme */
  URI_ECHECKERRNO      /* Look at errno for error code */
};

#if !defined(_URI_C_)
 extern const char* const _uri_errlist[];
#endif

/* A parsed URI */
typedef struct _uri {
  int   status;   /* Success or error code */
  char  *scheme;  /* Access scheme (http, mailto, etc) */
  char  *user;    /* Username for authentication */
  char  *pass;    /* Password for authentication */
  char  *host;    /* Server hostname */
  unsigned short port;     /* Service port number */
  char  is_explicit_port;  /* Whether an explicit port was set */
  char  *path;    /* Pathname (file, email address, etc) */
} URI, *PURI;

PURI uri_parse(char *uri);
PURI uri_new(void);
void uri_free(PURI puri);

#endif /* defined __URI_H__ */
