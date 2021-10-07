/*
 * Icon configuration file for Sun 4 running Solaris 2.x with Cygnus gcc
 */

#define UNIX 1
#define SUN
#define INTMAIN /* int main() */

#define LoadFunc
#define SysOpt
#define NoRanlib

/* CPU architecture */
#define Double
#define StackAlign 8

/* use gcc to compile generated code */
#define CComp "gcc"
#define COpts "-I/usr/openwin/include -ldl -lm -lXpm -lgdbm -ltp -lsocket -lnsl"

#define NEED_UTIME

#define Messaging 1
