 **QUICK NOTE -- save and recall your ideas instantly and reliably**

**TLDR: This is an experiment in efficiency for recording one's thoughts. #linuxTerminal #optimization #keyStrokeMinimization**

  **Quick Note is comprised of the following two programs:**
 
               qn              - make a quick note.
               qnl (script)    - display all quick notes (qnl="Quick Note List").

 **INSTALLATION:**
 
 The following has been tested on ubuntu (20.04 and 20.10), and pi3 raspbian (32bit): 

       make
       [SUDO] make install

This will copy two executables (qn and qnl) to /usr/local/bin. It will also create a directory in the user's home directory (~/.qn).

Please do give suggestions, advice, and offer MRs for improving quick-note and its installation process.


 **TO USE qn:**
 
       1) Open a terminal window (e.g.: Ctl+Atl+T).
       2) Type qn and hit return.
       3) Type or copy/paste your message and hit return.
      

 **TO USE qnl:**
 
       1) Open a terminal window.
       2) Type qnl and hit return. 
       3) All of your qn messages will be displayed.
       4) Of course, you can use grep at the command line. For instance, 
       if you want to see all your QuickNote messages with the word 'foo' in it, you could do: 
       qnl | grep foo
       Or qnl | grep https | grep github
       etc

 **WARNING** You cannot run qn or qnl as sudo, su, or root; an error message will display.

Type 'qn -h' to display help options and commands.

 **HOW IT WORKS:**
 
Each call to qn saves a .txt file in its directory (~/.qn). The call to qnl displays all those files to sysout (or can be grepped, etc).
 
 **WHY:**

	I believed I was having good thoughts, but I wasn't able to effectively record
	them before I forgot them, and many thoughts I thought were good were lost. 
	Often I would have a stream of thoughts, but the quality of that stream was compromised
	because I was looking for a pencil, or searching for a post-it or notepad, or the pen 
	was out of ink, or I was writing too slowly. I'd save my idea on a post-it, and then lose 
	the post-it. So I wrote this program, around the year 2009. I've been using it ever since, 
	and I thought maybe it's useful to other folks too. So here it is.

 
 **Existing users: move data from 1.001 to 1.002**
 
 Copy the tcc*.txt files from the previous user data directory (the one that qnl utilizes), to ~/.qn directory.

 **ENJOY:**
 
 May you find this program useful. May it prove beneficial for instantly and effectively recording your intuition, whenever it strikes.

 Tom Carbon 20201223
