/*  CS 570
    Assignment 1: This program simulate a chat system with
    7 bots, bots can update the chat log file asynchronously.
    This program uses the pthread library to create the bots,
    and the log file as the critical section is guarded by
    semaphore. The program is first tested on Ubuntu under
    VMware at home, then tested on edoras server.
    Dong Lin
*/
#include "bots.h"

int main()
{
    //initialize the variables, output process id
    init();

    //start the threads for the chat text
    start();

    //free the system resources
    release();

    return 0;
}
