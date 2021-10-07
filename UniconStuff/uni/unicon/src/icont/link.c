/*
 * link.c -- linker main program that controls the linking process.
 */

#include "link.h"
#include "tproto.h"
#include "tglobals.h"
#include "../h/header.h"

#if SCCX_MX
   #undef ISICONT
   #define ISICONT
   #include "ixhdr.h"
#endif					/* SCCX_MX */

#ifdef Header
   #ifndef ShellHeader
      #include "hdr.h"
   #endif					/* ShellHeader */
   #ifndef MaxHeader
      #define MaxHeader MaxHdr
   #endif					/* MaxHeader */
#endif					/* Header */

/*
 * Prototype.
 */

void	setexe	(char *fname);


/*
 * The following code is operating-system dependent [@link.01].  Include
 *  system-dependent files and declarations.
 */

#if PORT
   /* nothing to do */
   Deliberate Syntax Error
#endif					/* PORT */

#if AMIGA || ATARI_ST || MACINTOSH || VM || VMS
   /* nothing to do */
#endif					/* AMIGA || ATARI_ST || ... */

#if ARM
   #include "kernel.h"
   #include "swis.h"
#endif					/* ARM */

#if MSDOS
   extern char pathToIconDOS[];
   #if MICROSOFT || TURBO || BORLAND_286 || BORLAND_386
      #include <fcntl.h>
   #endif				/* MICROSOFT || TURBO ... */
#endif					/* MSDOS */

#if MVS
   char *routname;			/* real output file name */
#endif					/* MVS */

#if OS2
   #if MICROSOFT || CSET2
      #include <fcntl.h>
   #endif				/* MICROSOFT || CSET2 */
#endif					/* OS2 */

#if UNIX
   #ifdef CRAY
      #define word word_fubar
      #include <sys/types.h>
      #include <sys/stat.h>
      #undef word
   #else				/* CRAY */
      #ifndef XWindows
         #include <sys/types.h>
      #endif				/* XWindows */
      #include <sys/stat.h>
   #endif				/* CRAY */
#endif					/* UNIX */

/*
 * End of operating-system specific code.
 */

FILE *infile;				/* input file (.u1 or .u2) */
FILE *outfile;				/* interpreter code output file */

extern char *ofile;			/* output file name */

#ifdef DeBugLinker
   FILE *dbgfile;			/* debug file */
   static char dbgname[MaxFileName];	/* debug file name */
#endif					/* DeBugLinker */

char inname[MaxFileName];		/* input file name */
static char icnname[MaxFileName];	/* icon source file name */

struct lfile *llfiles = NULL;		/* List of files to link */

int colmno = 0;				/* current source column number */
int lineno = 0;				/* current source line number */
int fatals = 0;				/* number of errors encountered */

/*
 * cannotopen() - quitf with a detailed errno-based message
 */
void cannotopen(char *defaultmsg, char *filnam)
{
   char msgbuf[512];
   sprintf(msgbuf, "%s %%s", defaultmsg);
      switch (errno) {
      case EACCES: strcat(msgbuf, " due to permissions"); break;
      case EINTR: strcat(msgbuf, " due to interrupt"); break;
      case EISDIR: strcat(msgbuf, ", cannot write to a dir"); break;
      case EMFILE: strcat(msgbuf, "; app out of file handles"); break;
      case ENAMETOOLONG: strcat(msgbuf, "\n-- name too long"); break;
      case ENFILE: strcat(msgbuf,"; sys out of file handles"); break;
      case ENOENT: strcat(msgbuf,"; does not exist"); break;
      case ENOSPC: strcat(msgbuf,"; directory can't grow"); break;
      case ENOTDIR: strcat(msgbuf,"; bogus path"); break;
      case ENXIO: strcat(msgbuf,"; bogus device"); break;
#if !NT
      case ELOOP: strcat(msgbuf," due to symbolic link loop"); break;
      case EOVERFLOW: strcat(msgbuf,"; file too long"); break;
      case ETXTBSY: strcat(msgbuf,"; file is in use"); break;
#endif					/* !NT */
      case EROFS: strcat(msgbuf,"; read-only file system"); break;
      case EINVAL: strcat(msgbuf,"; bogus mode?!"); break;
      case ENOMEM: strcat(msgbuf,"; out of space"); break;
      }
   quitf(msgbuf,filnam);
}


/*
 *  ilink - link a number of files, returning error count
 */
int ilink(ifiles,outname)
char **ifiles;
char *outname;
   {


   int i;
   struct lfile *lf,*lfls;
   char *filename;			/* name of current input file */

   linit();				/* initialize memory structures */
   while (*ifiles)
      alsolink(*ifiles++);		/* make initial list of files */

   /*
    * Phase I: load global information contained in .u2 files into
    *  data structures.
    *
    * The list of files to link is maintained as a queue with llfiles
    *  as the base.  lf moves along the list.  Each file is processed
    *  in turn by forming .u2 and .icn names from each file name, each
    *  of which ends in .u1.  The .u2 file is opened and globals is called
    *  to process it.  When the end of the list is reached, lf becomes
    *  NULL and the loop is terminated, completing phase I.  Note that
    *  link instructions in the .u2 file cause files to be added to list
    *  of files to link.
    */
   for (lf = llfiles; lf != NULL; lf = lf->lf_link) {
      filename = lf->lf_name;
      makename(inname, SourceDir, filename, U2Suffix);
      makename(icnname, TargetDir, filename, SourceSuffix);

#if MVS || VM
      /*
       * Even though the ucode data is all reasonable text characters, use
       *  of text I/O may cause problems if a line is larger than LRECL.
       *  This is likely to be true with any compiler, though the precise
       *  disaster which results may vary.
       */
      infile = fopen(inname, ReadBinary);
#else					/* MVS || VM */
      infile = fopen(inname, ReadText);
#endif					/* MVS || VM */

      if (infile == NULL) {
	 makename(inname, SourceDir, filename, USuffix);
	 infile = fopen(inname, ReadText);
	 }

      if (infile == NULL) {
	 cannotopen("cannot open", inname); /* die w/ diagnostic */
	 }
      else if (verbose >= 5) {
	 fprintf(stderr, "linking %s\n", inname);
	 }
      readglob(lf);
      fclose(infile);
      }

   /* Phase II (optional): scan code and suppress unreferenced procs. */
   if (!strinv)
      scanrefs();

   /* Phase III: resolve undeclared variables and generate code. */

   /*
    * Open the output file.
    */

#if MVS
   routname = outname;
   outfile = tmpfile();         /* write icode to temporary file to
                                   avoid fseek-PDS limitations */
#else					/* MVS */
   #if AMIGA && __SASC
      outfile = fopen(outname, ReadWriteBinary);
   #else				/* AMIGA && __SASC */
      outfile = fopen(outname, WriteBinary);
   #endif				/* AMIGA && __SASC */
#endif					/* MVS */

/*
 * The following code is operating-system dependent [@link.02].  Set
 *  untranslated mode if necessary.
 */

#if PORT
   /* probably nothing */
   Deliberate Syntax Error
#endif					/* PORT */

#if AMIGA || ARM || ATARI_ST || MACINTOSH || MVS || UNIX || VM || VMS
   /* nothing to do */
#endif					/* AMIGA || ARM || ATARI_ST || ... */

#if MSDOS
   #if MICROSOFT || TURBO || BORLAND_286 || BORLAND_386
      setmode(fileno(outfile),O_BINARY);	/* set for untranslated mode */
   #endif				/* MICROSOFT || TURBO ... */
#endif					/* MSDOS */

#if OS2
   #if MICROSOFT || CSET2
      setmode(fileno(outfile),O_BINARY);
   #endif				/* MICROSOFT || CSET2 */
#endif					/* OS2 */

/*
 * End of operating-system specific code.
 */

   if (outfile == NULL) {		/* may exist, but can't open for "w" */
      char thecwd[512];
      ofile = NULL;			/* so don't delete if it's there */
      if ((getcwd(thecwd, 511) != NULL) && strstr(thecwd, "Program Files"))
	 quitf("cannot write %s to an installation directory\n"
	       "Try a folder not under 'Program Files'.", outname);

      cannotopen("cannot create", outname); /* die w/ detailed diagnostic */
      }


#if MSDOS && (!NT)
   /*
    * This prepends ixhdr.exe to outfile, so it'll be executable.
    *
    * I don't know what that #if Header stuff was about since my MSDOS
    * distribution didn't include "hdr.h", but it looks very similar to
    * what I'm doing, so I'll put my stuff here, & if somebody who
    * understands all the multi-operating-system porting thinks my code could
    * be folded into it, having it here should make it easy. -- Will Mengarini.
    */

   if (makeExe) {

#if SCCX_MX
    unsigned long i;

    if( makeExe == 1)
    {
        for( i=0; i<IXHDRSIZE; ++i)
            fputc( ixhdrarray[i], outfile);
        fileOffsetOfStuffThatGoesInICX = IXHDRSIZE;
    }
    else
    {
        FILE *fIconDOS = fopen(pathToIconDOS, "rb");
        char oneChar;

        if (!fIconDOS)
            quit("unable to find iconx.exe in same dir as icont");

        if (setvbuf(fIconDOS, 0, _IOFBF, 4096))
        {
            if (setvbuf(fIconDOS, 0, _IOFBF, 128))
                quit("setvbuf() failure");
        }

        fseek( fIconDOS, 0, 0);
        while( oneChar = fgetc( fIconDOS), !feof( fIconDOS) )
        {
            if( ferror( fIconDOS)  ||  ferror( outfile) )
                quit("Error copying iconx.exe");
            fputc( oneChar, outfile);
        }

        fclose (fIconDOS);
        fileOffsetOfStuffThatGoesInICX = ftell (outfile);
    }
#else					/* SCCX_MX */
      FILE *fIconDOS = fopen(pathToIconDOS, "rb");
      char bytesThatBeginEveryExe[2] = {0,0}, oneChar;
      unsigned short originalExeBytesMod512, originalExePages;
      unsigned long originalExeBytes, byteCounter;

      if (!fIconDOS)
         quit("unable to find ixhdr.exe in same dir as icont");
      if (setvbuf(fIconDOS, 0, _IOFBF, 4096))
         if (setvbuf(fIconDOS, 0, _IOFBF, 128))
            quit("setvbuf() failure");
      fread (&bytesThatBeginEveryExe, 2, 1, fIconDOS);
      if (bytesThatBeginEveryExe[0] != 'M' ||
          bytesThatBeginEveryExe[1] != 'Z')
         quit("ixhdr header is corrupt");
      fread (&originalExeBytesMod512, sizeof originalExeBytesMod512,
            1, fIconDOS);
      fread (&originalExePages,       sizeof originalExePages,
            1, fIconDOS);
      originalExeBytes = (originalExePages - 1)*512 + originalExeBytesMod512;

      if (ferror(fIconDOS) || feof(fIconDOS) || !originalExeBytes)
         quit("ixhdr header is corrupt");
      fseek (fIconDOS, 0, 0);

#ifdef MSWindows
      for (oneChar=fgetc(fIconDOS); !feof(fIconDOS); oneChar=fgetc(fIconDOS)) {
         if (ferror(fIconDOS) || ferror(outfile)) {
            quit("Error copying ixhdr.exe");
	    }
         fputc (oneChar, outfile);
         }
#else					/* MSWindows */

      for (byteCounter = 0; byteCounter < originalExeBytes; byteCounter++) {
         oneChar = fgetc (fIconDOS);
         if (ferror(fIconDOS) || feof(fIconDOS) || ferror(outfile)) {
            quit("Error copying ixhdr.exe");
	    }
         fputc (oneChar, outfile);
         }
#endif					/* MSWindows */

      fclose (fIconDOS);
      fileOffsetOfStuffThatGoesInICX = ftell (outfile);
#endif					/* SCCX_MX */
      }
#endif                                  /* MSDOS && (!NT) */

#ifdef Header
   /*
    * Write the bootstrap header to the output file.
    */

#ifdef ShellHeader
   /*
    * Write a short shell header terminated by \n\f\n\0.
    * Use magic "#!/bin/sh" to ensure that $0 is set when run via $PATH.
    * Pad header to a multiple of 8 characters.
    */
   {
   char script[2 * MaxPath + 300];

#if AMIGA
   sprintf(script,
   "/* ARexx header for direct execution of Icon code */\n\
   PARSE SOURCE type flag filename fullname ext host\n\
   PARSE ARG 1 args 1\n\
   SIGNAL ON ERROR\n\
   ADDRESS command\n\
   \"%s\" fullname args\n\
   ERROR:\n\
   EXIT\n\
   /*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*\n[executable Icon binary follows]\n",
   iconxloc);
   strcat(script, "        \n\f\n" + ((int)(strlen(script) + 4) % 8));
   hdrsize = strlen(script) + 1;	/* length includes \0 at end */
   fwrite(script, hdrsize, 1, outfile);	/* write header */
#endif                                  /* AMIGA */

#if NT
   /*
    * The NT and Win95 direct execution batch file turns echoing off,
    * launches wiconx, attempts to terminate softly via noop.bat,
    * and terminates the hard way (by exiting the DOS shell) if that
    * fails, rather than fall through and start executing machine code
    * as if it were batch commands.
    *
    * Should we add quoting \"...\" around %s or %0 in the code below?
    */
   sprintf(script,
           "@echo off\r\n%s %%0 %%1 %%2 %%3 %%4 %%5 %%6 %%7 %%8 %%9\r\n",
           ((iconxloc!=NULL)?iconxloc:"wiconx"));
   strcat(script,"noop.bat\r\n@echo on\r\n");
   strcat(script,"pause missing noop.bat - press ^c or shell will exit\r\n");
   strcat(script,"exit\r\nrem [executable Icon binary follows]\r\n");
   strcat(script, "        \n\f\n" + ((int)(strlen(script) + 4) % 8));
   hdrsize = strlen(script) + 1;	/* length includes \0 at end */
   fwrite(script, hdrsize, 1, outfile);	/* write header */
#endif					/* NT */
#if UNIX
   /*
    *  Generate a shell header that searches for iconx in this order:
    *     a.  location specified by ICONX environment variable
    *         (if specified, this MUST work, else the script exits)
    *     b.  iconx in same directory as executing binary
    *     c.  location specified in script
    *         (as generated by icont or as patched later)
    *     d.  iconx in $PATH
    *
    *  The ugly ${1+"$@"} is a workaround for non-POSIX handling
    *  of "$@" by some shells in the absence of any arguments.
    *  Thanks to the Unix-haters handbook for this trick.
    */
   sprintf(script, "%s\n%s%-72s\n%s\n\n%s\n%s\n%s\n%s%s%s\n\n%s\n",
      "#!/bin/sh",
      "IXBIN=", iconxloc,
      "IXLCL=`echo $0 | sed 's=[^/]*$=iconx='`",
      "[ -n \"$ICONX\" ] && exec \"$ICONX\" \"$0\" ${1+\"$@\"}",
      "[ -x \"$IXLCL\" ] && exec \"$IXLCL\" \"$0\" ${1+\"$@\"}",
      "[ -x \"$IXBIN\" ] && exec \"$IXBIN\" \"$0\" ${1+\"$@\"}",
      "exec ",
      "iconx",
      " \"$0\" ${1+\"$@\"}",
      "[executable Icon binary follows]");
#if __clang__
   /* clang doesn't much like the strcat code below and recommends array indexing instead. i.e.
	*       strcat(script, &"        \n\f\n"[((int)(strlen(script) + 4) % 8)]);
	* but the code is well defined standard C, so we'll just temporarily suppress clang's fastidiousness
	*/
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wstring-plus-int"
#endif
   strcat(script, "        \n\f\n" + ((int)(strlen(script) + 4) % 8)); /* Guarantee longword (8 byte) alignment for following data */
#if __clang__
#pragma clang diagnostic pop
#endif
   hdrsize = strlen(script) + 1;	/* length includes \0 at end */
   fwrite(script, hdrsize, 1, outfile);	/* write header */
#endif					/* UNIX */
   }
#else					/* ShellHeader */
   /*
    *  Always write MaxHeader bytes.
    */
   fwrite(iconxhdr, sizeof(char), MaxHeader, outfile);
   hdrsize = MaxHeader;
#endif					/* ShellHeader */
#endif					/* Header */

   for (i = sizeof(struct header); i--;)
      putc(0, outfile);
   fflush(outfile);
   if (ferror(outfile) != 0)
      quit("unable to write to icode file");

#ifdef DeBugLinker
   /*
    * Open the .ux file if debugging is on.
    */
   if (Dflag) {
      makename(dbgname, TargetDir, llfiles->lf_name, ".ux");
      dbgfile = fopen(dbgname, WriteText);
      if (dbgfile == NULL)
         quitf("cannot create %s", dbgname);
      }
#endif					/* DeBugLinker */

   /*
    * Loop through input files and generate code for each.
    */
   lfls = llfiles;
   while ((lf = getlfile(&lfls)) != 0) {
     if (!(lf->lf_name))
     continue;

      filename = lf->lf_name;
      makename(inname, SourceDir, filename, U1Suffix);
      makename(icnname, TargetDir, filename, SourceSuffix);

#if MVS || VM
      infile = fopen(inname, ReadBinary);
      if (infile != NULL)         /* discard the extra blank we had */
         (void) getc(infile);     /* to write to make it non-empty  */
#else                                   /* MVS || VM */
      infile = fopen(inname, ReadText);
#endif                                  /* MVS || VM */


      if (infile == NULL) {
	 int c;
	 makename(inname, SourceDir, filename, USuffix);
	 infile = fopen(inname, ReadText);
	 if (infile == NULL)
	    quitf("cannot open .u or .u1 for %s", inname);
	 if (((c = getc(infile)) != 'v') ||
	     ((c = getc(infile)) != 'e') ||
	     ((c = getc(infile)) != 'r') ||
	     ((c = getc(infile)) != 's')) {
	    quitf("'%s' is not a ucode file", inname);
	    }
	 /*
	  * skip past the control-L
	  */
	 while ((c = getc(infile)) != EOF)
	    if (c == '\014') {
	       c = getc(infile);
	       if (c == '\r') getc(infile);
	       break;
	       }
	 }

      if (infile == NULL)
         quitf("cannot open %s", inname);
      gencode();

      fclose(infile);
      }


   gentables();		/* Generate record, field, global, global names,
			   static, and identifier tables. */

#if AMIGA
#ifdef ShellHeader
   /* The icode is enclosed in a deeply nested ARexx comment.
      Here we close up the comment. */
     {
     int c, count = 0, state = 0;

     rewind(outfile);
     while ((c = fgetc(outfile)) != EOF)
       switch(state){
         case 0:  /* start state */
           if (c == '/' || c == '*') state = c;
           break;
         case '/':
           if (c == '*') count++;
           state = 0;
           break;
         case '*':
           if (c == '/') count--;
           state = 0;
           break;
         }
     if (count < 0){
       fprintf(stderr, "       Failed to write direct execution header.\n\
       You will have to use iconx to execute %s.\n", outname);
       outname = NULL;
       }
     else {
       fseek(outfile, 0, SEEK_END);
       while (0 < count--){
         fputc('*', outfile);
         fputc('/', outfile);
         }
       }
     }
#endif					/* ShellHeader */
#endif					/* AMIGA */

   fclose(outfile);
   lmfree();
   if (fatals > 0)
      return fatals;
   setexe(outname);
   return 0;
   }

#ifdef ConsoleWindow
   extern FILE *flog;
#endif					/* ConsoleWindow */
/*
 * lwarn - issue a linker warning message.
 */
void lwarn(s1, s2, s3)
char *s1, *s2, *s3;
   {

#ifdef ConsoleWindow
   if (flog != NULL) {
      fprintf(flog, "%s: ", icnname);
      if (lineno)
         fprintf(flog, "Line %d # :", lineno);
      fprintf(flog, "\"%s\": %s%s\n", s1, s2, s3);
      fflush(flog);
      if (silent)
	 return;
      }
#endif					/* ConsoleWindow */
   fprintf(stderr, "%s: ", icnname);
   if (lineno)
      fprintf(stderr, "Line %d # :", lineno);
   fprintf(stderr, "\"%s\": %s%s\n", s1, s2, s3);
   fflush(stderr);
   }

/*
 * lfatal - issue a fatal linker error message.
 */

void lfatal(s1, s2)
char *s1, *s2;
   {

   fatals++;
#ifdef ConsoleWindow
   if (flog != NULL) {
      fprintf(flog, "%s: ", icnname);
      if (lineno)
         fprintf(flog, "Line %d # : ", lineno);
      fprintf(flog, "\"%s\": %s\n", s1, s2);
      if (silent)
	 return;
      }
#endif					/* ConsoleWindow */
   fprintf(stderr, "%s: ", icnname);
   if (lineno)
      fprintf(stderr, "Line %d # : ", lineno);
   fprintf(stderr, "\"%s\": %s\n", s1, s2);
   }

/*
 * setexe - mark the output file as executable
 */

void setexe(fname)
char *fname;
   {

/*
 * The following code is operating-system dependent [@link.03].  It changes the
 *  mode of executable file so that it can be executed directly.
 */

#if PORT
   /* something is needed */
Deliberate Syntax Error
#endif					/* PORT */

#if AMIGA
   #if __SASC
      if (fname != NULL) {
      struct DiskObject *dob;
   
      chmod(fname,S_ISCRIPT|S_IREAD|S_IWRITE|S_IEXECUTE|S_IDELETE);
      /* Create a WorkBench Icon if necessary. */
      dob = GetDiskObject(fname);
      if (dob == NULL) {
         dob = GetDiskObject(IconIcon);
         if ( dob ) {
            dob->do_CurrentX = NO_ICON_POSITION;
            dob->do_CurrentY = NO_ICON_POSITION;
            PutDiskObject(fname, dob);
            }
         }
      if ( dob ) FreeDiskObject(dob);
      }
   #endif                                  /* __SASC */
#endif					/* AMIGA */

#if ARM
   {
      _kernel_swi_regs regs;

      regs.r[0] = 31;
      regs.r[1] = (int)"Icon";
      if (_kernel_swi(OS_FSControl,&regs,&regs) == NULL)
      {
         regs.r[0] = 18;
         regs.r[1] = (int)fname;
         _kernel_swi(OS_File,&regs,&regs);
      }
   }
#endif					/* ARM */

#if ATARI_ST || MSDOS || MVS || VM || VMS
   /*
    * can't be made executable
    * note: VMS files can't be made executable, but see "iexe.com" under VMS.
    */
#endif					/* ATARI_ST || MSDOS || ... */

#if MACINTOSH
   #if MPW
      /* Nothing to do here -- file is set to type TEXT
         (so it can be executed as a script) in tmain.c.
      */
   #endif				/* MPW */
#endif					/* MACINTOSH */

#if MSDOS
   #if MICROSOFT || TURBO || BORLAND_286 || BORLAND_386
      chmod(fname,0755);	/* probably could be smarter... */
   #endif				/* MICROSOFT || TURBO ... */
#endif					/* MSDOS */

#if OS2
    /*
     *	Obtain the EXE stub resource from icont (or xicont)
     *	and write it out as the executable name.  Invoke the resource
     *	compiler to add the icode file as a resource to the executable
     *	This should be portable to Windows NT I believe.  Cheyenne.
     */
    {
	char	*exeres;		/* EXE stub resource pointer */
	unsigned long exereslen;	/* Length of resource */
	char loadmoderr[256];

	char exename[256];
	char rcname[256];
	char cmdbuffer[256];
	FILE *exefile;
	FILE *rcfile;

	if( noexe ) return;		/* Nothing to do.. */

	DosGetResource(0,0x4844,1,&exeres);
	DosQueryResourceSize(0,0x4844,1,&exereslen);

	makename(exename,NULL,fname,".exe");
	exefile = fopen(exename,WriteBinary);
	fwrite( exeres, sizeof(char), exereslen, exefile);
	fclose(exefile);
	DosFreeResource(exeres);

	makename(rcname,NULL,fname,".rc");
	rcfile = fopen(rcname,WriteText);

	fprintf(rcfile,"RESOURCE 0x4843 1 %s\n",fname);
	fclose(rcfile);

	sprintf(cmdbuffer,"rc %s %s",rcname,exename);

	system(cmdbuffer);

	remove(rcname);
	makename(rcname,NULL,fname,".res");
	remove(rcname);
	remove(fname);
    }
#endif					/* OS2 */

#if UNIX
      {
      struct stat stbuf;
      int u, r, m;
      /*
       * Set each of the three execute bits (owner,group,other) if allowed by
       *  the current umask and if the corresponding read bit is set; do not
       *  clear any bits already set.
       */
      umask(u = umask(0));		/* get and restore umask */
      if (stat(fname,&stbuf) == 0)  {	/* must first read existing mode */
         r = (stbuf.st_mode & 0444) >> 2;	/* get & position read bits */
         m = stbuf.st_mode | (r & ~u);		/* set execute bits */
         chmod(fname,m);		 /* change file mode */
         }
      }
#endif					/* UNIX */

/*
 * End of operating-system specific code.
 */
   }
