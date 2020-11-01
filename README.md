 **QUICK NOTE -- save and recall your ideas instantly and reliably**

  **Quick Note is comprised of the following two programs:**
 
               qn              - make a quick note.
               qnl (script)    - display all quick notes (qnl="Quick Note List").
        
 **INSTALLATION:**
 
 The following has been tested on ubuntu 20.10: 

       MAKE
       [SUDO] MAKE INSTALL

This will copy two executables (qn and qnl) to /usr/local/bin. It will also create a directory in the user's home directory (~/.qn).

Please do give suggestions, advice, and offer MRs for improving quick-note and its installation process.


 **TO USE qn:**
 
       1) Open a terminal window (e.g.: Ctl+Atl+T).
       2) Type qn and hit return.
       3) Type or copy/paste your message and hit return.
      
   **WARNING** You cannot run qn or qnl as sudo, su, or root; an error message will display.

 **TO USE qnl:**
 
       1) Open a terminal window.
       2) Type qnl and hit return. 
       3) All of your qn messages will be displayed.
       4) Of course, you can use grep at the command line. For instance, 
       if you want to see all your QuickNote messages with the word 'foo' in it, you could do: 
       qnl | grep foo
       Or qnl | grep https | grep github
       etc

 qn and qnl do not use command line arguments. qn will display help information 
 if any arguments are given to it.

 **HOW IT WORKS:**
 
 qn saves a little .txt file in its directory (~/.qn). qnl displays all those files to the screen. 
 
 **WHY:**

               I believed I was having good thoughts, but I wasn't able to effectively record
               them before I forgot them, and many thoughts I thought were good were lost. 
               Often I would have a stream of thoughts, but the quality of that stream was compromised
               because I was looking for a pencil, or searching for a post-it or notepad, or the pen 
               was out of ink, or I was writing too slowly. So I wrote this program, around the year 
               2009. I've been using it ever since, and I thought maybe it's useful to other folks too, so here it is.

 
 **ENJOY:**
 
 May you find this program useful.  
 Tom Carbon 20201101
