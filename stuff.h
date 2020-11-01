/*********************************************************************
* STUFF_QN.H
* Tom Chamberlain 090418
*********************************************************************/
 
/****************************************************
* INCLUDE FILES
*****************************************************/
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <pwd.h>

#define USER_DATA_DIR ".qn"
#define TCC_FILEMAX	99999	// # files to have for tcc00000.txt

/****************************************************
* FUNCTION DECLARATIONS from tomutils.h
*****************************************************/
void make_time_and_date(void);   // print out the date
long atolnum(char *,long);	// Convert long digits of stg to long value.
long kbhit(void);
void nonblock(long sstate); 	// support for kbhit()
int dirExists(const char *);	// 1 if exists, 0 if not
#define NB_ENABLE 1		// for function nonblock
#define NB_DISABLE 2 		// for function nonblock

/*****************************************************
* GLOBAL STRUCTURE HOLDER
******************************************************/
typedef struct tagUVGLOB
{
	struct tm	*ts;
	time_t		now;
	char 		tempbuf[1000];
	long today_date;		// yyymmdd date of today 
	long today_time;		// hhsstt time of today
} UVGLOB;
 
#ifdef MMAIN
/*****************************************************
* MAIN GLOBALS
******************************************************/
UVGLOB uvglob;				/* this holds all the globals! */

#else
/*****************************************************
* the externs that were defined in the main globals
*******************************************************/
extern UVGLOB uvglob;			/* this holds all the globals! */

#endif 

