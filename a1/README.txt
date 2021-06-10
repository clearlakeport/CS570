Assignment 1 for CS 570
Summer, 2021

Description
This program simulates a chat system with 7 bots, bots can update the chat log file asynchronously. This program uses the pthread library to create the bots, and the log file as the critical section is guarded by a semaphore. The program is first tested on Ubuntu under VMware 
at home, then tested on edoras server.

Requirements
The project is written in C and requires adding the pthread and semaphore libraries for the linker. It has been tested under linux.

compilation
Use the included Makefile.

Example
See the “QUOTE.txt” file for a sample run.

Configuration
See the Makefile

Testing
It has been tested on a home machine running Ubuntu 20.04 on VMware Player 16 and edoras. 

Members
Dong Lin

Licensing
No license is required.

