Assignment 2 for CS 570
Summer, 2021

Description
This program implement a microshell, "MSH" that provides the following functions:
1. Provide a shell-like interface to launch new programs.
2. It executes programs with either no arguments or one argument.
3. It executes programs using both fully qualified path name or just the excutables.
4. It executes two processes connected by a pipe.

Requirements
This program works on Linux and it is written in C.

Lessons Learned
I learned a lot about creating a process and excuting a command in a child process in Linux.
I also learned how to directing input to output between processes.
 
Compilation
Use the included Makefile. 
make clean
make

Files
main.c  driver
msh.h   header
msh.c   functions for chat bot
Makefile
README.txt

Configuration
See the Makefile

Testing
It has been tested on a home machine running Ubuntu 20.04 on VMware Player 16 and edoras. 

Limitations
The pipe only works with two processes and it will not chain commands.

Members
Dong Lin
cssc4206
redid: 827228799

Licensing
No license is required.

