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
* May you find it useful. Tom Carbon 20201223
*************************************************************************/
#define MMAIN 1
#include "stuff.h"


int main(int argc, char *argv[])
{
long i;
long x;
FILE *fin;
char *pret;
long tcclatestfile;
char user_directory_path[500];
char saved_string[500];
const char *homedir;

	memset(saved_string,0x00, 500);

	if ((homedir = getenv("HOME")) == NULL) {
	    homedir = getpwuid(getuid())->pw_dir;
	}

	printf("\nQN (QuickNote) (v%s) -h for help",VVERSION);
	sprintf(user_directory_path,"%s/%s", homedir, USER_DATA_DIR);
	if (dirExists(user_directory_path)) {
		// do nothing
	} else {
		printf("\nFATAL ERROR: The directory %s does not exist!\nCreate this directory to enable quick-note for this user.\nsudo/su/root is not allowed for qn.", user_directory_path);
		exit(40);
	}

	for (i=0; i<argc; i++) {
		if (!memcmp("--version", argv[i], 9) ||
		    !memcmp("-version", argv[i], 8) ||
		    !memcmp("-v", argv[i], 2)) {
			printf("\n%s\n",VVERSION);
			return 0;
		} 
		else if (!memcmp("--info", argv[i], 6) ||
		    !memcmp("-info", argv[i], 5) ||
		    !memcmp("-i", argv[i], 2)) {
			printf("\nVERSION: %s", VVERSION);
			printf("\nHOMEDIR: %s", homedir);
			printf("\nUSER_DATA_DIR: %s", USER_DATA_DIR);
			printf("\nUSER DIRECTORY PATH: %s", user_directory_path);
			printf("\n");
			return 0;
		}
		else if (!memcmp("--list", argv[i], 6) ||
		    !memcmp("-list", argv[i], 5) ||
		    !memcmp("-l", argv[i], 2)) {
			printf("\nHere is the list of your quick notes:");
			printf("\n*************************************\n");
			execl("qnl","","",NULL);
			return 0;
			
		}
		else if (!memcmp("--save", argv[i], 6) ||
		    !memcmp("-save", argv[i], 5) ||
		    !memcmp("-s", argv[i], 2)) {
			if (i == argc-1) {
				printf("\nERROR: No message provided for --save option.\n");
				return 1;
			}
			for (x=i+1; x<argc; x++) {
				memcpy((char *)&saved_string[strlen(saved_string)], argv[x], strlen(argv[x]));
				if (x+1 != argc) {
					saved_string[strlen(saved_string)] = ' ';
				}
			}
			printf("\nSaving the following as a Quick-Note: \n%s\n", saved_string);
		}
		else if (!memcmp("--commands", argv[i], 10) ||
		    !memcmp("-commands", argv[i], 9) ||
		    !memcmp("--help", argv[i], 6) ||
		    !memcmp("-help", argv[i], 5) ||
		    !memcmp("-?", argv[i], 2) ||
		    !memcmp("-h", argv[i], 2)) {
			printf("\n***************************************************************");
			printf("\n***************************************************************");
			printf("\n*** QUICK-NOTE (v%s)",VVERSION);
			printf("\n***************************************************************");
			printf("\n***************************************************************");
			printf("\n* How to use qn: ");
			printf("\n* 	1) Open a terminal window.");
			printf("\n* 	2) Type qn and hit return.");
			printf("\n* 	3) Type or copy/paste your message and hit return.");
			printf("\n*");
			printf("\n* To use qnl:");
			printf("\n* 	1) Open a terminal window.");
			printf("\n* 	2) Type qnl and hit return. ");
			printf("\n* 	3) All of your qn messages will be displayed.");
			printf("\n*");
			printf("\n* Quick-Note also takes the following input parameters:");
			printf("\n*   -h, --help       This help screen");
			printf("\n*   -i, --info       Display program information");
			printf("\n*   -l, --list       List all Quick-Note messages (same as qnl)");
			printf("\n*   -s, --save       Save everything after this param as a Quick Note message");
			printf("\n*   -v, --version    Display version information");
			printf("\n");
			return 1;
		}
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
	if (saved_string[0] != 0x00) {		// --save option
		sprintf(uvglob.tempbuf, "%s\n", saved_string);
	}
	else {
		printf("Write what you want to write below:\n:");
		pret = fgets(uvglob.tempbuf,255,stdin);
		if (!pret)
		{
			printf("\nERROR: Cannot read in user Quick Note!");
			fclose(fin);
			exit (40);
		}
	}

	fprintf(fin,"%s",uvglob.tempbuf);

	fclose(fin);
return 0;
}
