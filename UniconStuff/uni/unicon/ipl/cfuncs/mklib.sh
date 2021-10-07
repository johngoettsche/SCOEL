#!/bin/sh
#
#  mklib libname.so obj.o ...

CC=${CC-cc}

LIBNAME=${1?"usage: $0 libname obj..."}
shift

SYS=`uname -sr | sed 's/ //'`
set -x
case "$SYS" in
   SunOS4*)
      ld -o $LIBNAME "$@";;
   SunOS5*)
      $CC $CFLAGS -G -o $LIBNAME "$@" -lc -lsocket;;
   AIX*)
      # this may not be quite right; it doesn't seem to work yet...
      ld -bM:SRE -berok -bexpall -bnoentry -bnox -bnogc -brtl -o $LIBNAME "$@";;
   IRIX*)
      ld -shared -o $LIBNAME "$@";;
   OSF*)
      ld -shared -expect_unresolved '*' -o $LIBNAME "$@" -lc;;
   Linux*|BSD/OS*|OpenBSD*)
      gcc -shared -o $LIBNAME -fPIC "$@";;
   Darwin*)
      cc -Xlinker -dylib -Xlinker -undefined -Xlinker dynamic_lookup -shared -o $LIBNAME -fPIC "$@";;
   FreeBSD*)
      ld -Bshareable -o $LIBNAME "$@" -lc;;
   *)
      set -
      echo 1>&2 "don't know how to make libraries under $SYS"
      exit 1;;
esac
