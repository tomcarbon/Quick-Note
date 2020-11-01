 **QUICK NOTE -- save and recall your ideas instantly and reliably**

  **Quick Note is comprised of the following two programs:**
 
               qn              - make a quick note.
               qnl (script)    - display all quick notes (qnl="Quick Note Look").
        
 **INSTALLATION:**
 
       Change the DDIRNAME in qn.c to point to your directory. make the program.
       ALSO create the alias in the .bashrc (or equivalent) for qn and qnl, like so:
               alias qn='//home/yourdirectory/Code/qn/qn';
               alias qnl='//home/yourdirectory/Code/qn/qnl';
       ALSO edit qnl and correctly point that to the directory. And then chmod it if you have to.

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
       Or qnl | grep https | grep linkedin
       etc
       etc
       etc

 qn and qnl do not use command line arguments. qn will display help information 
 if any arguments are given to it.

 **HOW IT WORKS:**
 
 qn saves a little .txt file in its directory. qnl displays all those files to the screen. 
 
 **WHY:**

               I believed I was having good thoughts, but I wasn't able to effectively record
               them before I forgot them, and many thoughts I thought were good were lost. 
               Often I would have a stream of thoughts, but the quality of that stream was compromised
               because I was looking for a pencil, or searching for a post-it or notepad, or the pen 
               was out of ink, or I was writing too slowly. So I wrote this program, around the year 
               2009. I've been using it ever since, and I thought maybe it's useful to other folks too, so 
               here it is.

 
 **ENJOY:**

 
 May you find this program useful.  
 Tom Carbon 20200417
