Assignment 1 for CS 570
Summer, 2021

Description
This program simulates a chat system with 7 bots, bots can update the chat log file asynchronously. This program uses the pthread library to create the bots, and the log file as the critical section is guarded by a semaphore. The program is first tested on Ubuntu under VMware 
at home, then tested on edoras server.

Requirements
The project is written in C and requires adding the pthread and semaphore libraries for the linker. It has been tested under linux.

Description
Due to all 7 bots want to access the chat file, a semaphore is needed to lock the chat file to prevent race condition.
When one bot is writing to the chat file, it enters the critical section, the semaphore locks this shared resource
to prevent accidentally being overwritten by another bot at the same time. Once the writting is done, the bot releases the lock so other bots can write to it.

Lessons Learned
I learned a lot of thread and semaphore and how they work in Linux system.
 
Compilation
Use the included Makefile. 
make clean
make

Files
main.c  driver
bot.h   header
bot.c   functions for chat bot
README.txt
QUOTE.txt   output

Configuration
See the Makefile

Testing
It has been tested on a home machine running Ubuntu 20.04 on VMware Player 16 and edoras. 

Members
Dong Lin

Licensing
No license is required.

