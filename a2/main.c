/*  CS 570
    Assignment 2: This program implement a Microshell, "MSH".
    MSH provide a shell-like interface for launching new programs.
    It displays "cssc4206%" as the prompt then waits for the user to
    type a file name. It reads the user input and try to determine
    if the file is an executable file. If it is not an executable, it
    display an error message and wait for user input again. If an
    executable file name is entered, it will create a new process and
    run the executable inn the new process. Both fully qualified path
    name or just the executable file names are accepted. MSH also supports
    the user to use pipe for two processes to communicated with each
    other. MSH also need to support exit to close itself down and
    terminate.
    Dong Lin
    cssc4206
    redid: 827228799
    Summer, 2021
*/
#include "msh.h"

int main()
{
    init();

    startShell();

    return 0;
}
