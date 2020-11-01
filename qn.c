/***********************************************************************
* qn.c
* QUICK NOTE
*
* OVERVIEW:
*	qn is a simple C program, a LINUX terminal program, designed to do one thing:
*		Record that thought quickly and permanently. 
*
*	Quick Note is comprised of the following two programs:
*		qn		- make a quick note.
*		qnl (script) 	- display all quick notes (qnl="Quick Note Look").
* 	 
* TO USE qn: 
* 	1) Open a terminal window (e.g.: Ctl+Atl+T).
* 	2) Type qn and hit return.
* 	3) Type or copy/paste your message and hit return.
* TO USE qnl:
* 	1) Open a terminal window.
* 	2) Type qnl and hit return. 
* 	3) All of your qn messages will be displayed.
*
* qn and qnl do not use command line arguments. qn will display help information 
* if any arguments are given to it.
*
* HOW IT WORKS: qn saves a little .txt file in its directory. qnl displays all those files to the screen. 
* 
* RAMBLE: I believed I was having good thoughts, but I wasn't able to effectively record
* them before I forgot them, and many thoughts I thought were good were lost. 
* Often I would have a stream of thoughts, but the quality of that stream was compromised
* because I was looking for a pencil, or searching for a post-it or notepad, or the pen was out of ink, or
* I was writing too slowly. So I wrote this program, sometime before the year 2009, and wrote this intro today.
*
* May you find it useful. Tom Carbon 20201101
* Tip Jar: https://dogepal.com/index.html?DPC=TCARBON#DPC
*************************************************************************/
#define MMAIN 1
#include "stuff.h"


int main(int argc, char *argv[])
{
long i;
FILE *fin;
char *pret;
long tcclatestfile;
char user_directory_path[500];
const char *homedir;

if ((homedir = getenv("HOME")) == NULL) {
    homedir = getpwuid(getuid())->pw_dir;
}

sprintf(user_directory_path,"%s/%s", homedir, USER_DATA_DIR);
printf("dirname = %s", user_directory_path);
if (dirExists(user_directory_path)) {
	printf("directory DOES exist");
} else {
	printf("\nFATAL ERROR: The directory %s does not exist!\nCreate this directory to run quick-note for this user.\n", user_directory_path);
	exit(40);
}
	/**********************************************************
	* Print out QN version info and Current Date and Time here:
	***********************************************************/
	printf("\nQN (QuickNote) version 1.002 20201101\n");
	if (argc != 1) {
		system("tput clear");
		printf("***************************************************************\n");
		printf("***************************************************************\n");
		printf("***   QN TAKES NO ARGUMENTS. WELCOME TO THE HELP BLURB.     ***\n");
		printf("***************************************************************\n");
		printf("***************************************************************\n");
		printf("* How to use qn: ");
		printf("\n* 	1) Open a terminal window (e.g.: Ctl+Atl+T).");
		printf("\n* 	2) Type qn and hit return.");
		printf("\n* 	3) Type or copy/paste your message and hit return.");
		printf("\n*");
		printf("\n* To use qnl:");
		printf("\n* 	1) Open a terminal window.");
		printf("\n* 	2) Type qnl and hit return. ");
		printf("\n* 	3) All of your qn messages will be displayed.\n");
		return 1;
	}

	make_time_and_date();

 	/**********************************************************
	* Start with tcc00000.txt and move up from there until one 
	* isn't found.
	**********************************************************/
	for (i=0;i<TCC_FILEMAX;i++)
	{
		sprintf(uvglob.tempbuf,"%s/tcc%05ld%s",user_directory_path,i,
					".txt");
		fin = fopen(uvglob.tempbuf,"rb");
		if (fin) 
		{
			fclose(fin);
		}
		else
		{
			tcclatestfile = i;
			i = TCC_FILEMAX;
		}
	}

	
	/*******************************************
	* Open up the output text file
	*******************************************/
	sprintf(uvglob.tempbuf,"%s/tcc%05ld%s",user_directory_path,tcclatestfile,
		".txt");
	fin = fopen(uvglob.tempbuf,"w");
	if (ferror(fin))
	{
		printf("\nError opening %s for writing!",uvglob.tempbuf);
		exit(40);
	}

	/********************************************************
	* Read in the quick note, and write it
	*********************************************************/
	printf("Write what you want to write below:\n:");
	pret = fgets(uvglob.tempbuf,255,stdin);
	if (!pret)
	{
		printf("\nERROR: Cannot read in user Quick Note!");
		fclose(fin);
		exit (40);
	}

	fprintf(fin,"%s",uvglob.tempbuf);

	fclose(fin);
return 0;
}
