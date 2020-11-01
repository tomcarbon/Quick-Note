/*****************************************************************
* TOMUTILS.C
* This module contains bits and pieces of things that may or may
* not be useful. 
******************************************************************/
#include "stuff.h"


void make_time_and_date(void)
{
 
	uvglob.now = time(NULL);

	uvglob.ts = localtime(&uvglob.now);
  	
	uvglob.today_date = (uvglob.ts->tm_year *10000) +
 			    ((uvglob.ts->tm_mon+1)*100) +
			    (uvglob.ts->tm_mday);

	uvglob.today_time = (uvglob.ts->tm_hour * 10000) + 
			    (uvglob.ts->tm_min  * 100)   +
			    (uvglob.ts->tm_sec);

	printf("\nToday's Date is %ld",uvglob.today_date);
	printf("\nToday's Time is %06ld\n",uvglob.today_time);
 

return;
}

/*********************************************************************
* atolnum - convert string to long, when we know # of digits in string
**********************************************************************/
long atolnum(char *stg,long len)
{
char tempbuf[25];

	memcpy(tempbuf,stg,len);
	tempbuf[len] = 0x00;

return atol(tempbuf);
}


long kbhit (void)
{
struct timeval tv;

fd_set rdfs;
tv.tv_sec = 0;
tv.tv_usec = 0;
FD_ZERO(&rdfs);
FD_SET (STDIN_FILENO, &rdfs);

select(STDIN_FILENO+1, &rdfs, NULL, NULL, &tv);

return FD_ISSET(STDIN_FILENO, &rdfs);
}


void nonblock(long state)  
{  
    struct termios ttystate;  
   
    //get the terminal state  
    tcgetattr(STDIN_FILENO, &ttystate);  
    if (state==NB_ENABLE)  
    {  
        //turn off canonical mode  
        ttystate.c_lflag &= ~ICANON;  
        //minimum of number input read.  
        ttystate.c_cc[VMIN] = 1;  
     }  
    else if (state==NB_DISABLE)  
     {  
        //turn on canonical mode  
         ttystate.c_lflag |= ICANON;  
     }  
     //set the terminal attributes.  
     tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);  
  
}  

int dirExists(const char *path)
{
    struct stat info;

    if(stat( path, &info ) != 0)
        return 0;
    else if(info.st_mode & S_IFDIR)
        return 1;
    else
        return 0;
}
