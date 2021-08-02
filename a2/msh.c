/*  Dong Lin
    cssc4206
    redid: 827228799
*/
#include "msh.h"

//init the prompt and print instructions
void init()
{
    const char USER[] = "cssc4206% ";

    // get the prompt
    strcpy(prompt, USER);

    // clear screen
    printf("\033[2J\033[1;1H");
    printf("Please enter executable files as:\n");
    printf("%s executablefilename\n", prompt);
    printf("%s executablefilename argument\n", prompt);
    printf("%s executablefilename | executablefilename\n", prompt);
    printf("%s exit - to exit the program\n\n\n", prompt);
}

//check for exit
bool checkExit(char* str)
{

    if (strcmp(str, "exit") == 0)
        return true;
    else
        return false;

}

//the shell loop
void startShell()
{
    char comArgs[STR_LENGTH], *charPtr; //for getting the command
    const char PCH = '|';   //detect the pipe
    pid_t pid;
    char *com[COMMAND_LEN]; //break into command and arguments
    char p1[COMMAND_LEN], p2[COMMAND_LEN];  //for pipe
    int c, count = 0, i, argc, pos, pos2;
    bool done = false;

    for (i = 0; i < COMMAND_LEN; i++) //command and args array
        com[i] = NULL;

    do
    {
        printf("%s ", prompt);

        //get the command and arguments
        while ((c = getchar()) != '\n')
        {
            comArgs[count++] = c;
        }
        comArgs[count] = '\0';  //null terminate the c-string

        //if only return key are pressed
        if (count == 0 && c == '\n')
            continue;


        if (checkExit(comArgs))
            break; //if exit, return to main

        //check if there is a pipe
        if ((charPtr = strchr(comArgs, PCH)) != NULL)
        {
            if (strchr(charPtr+1, PCH) == NULL)
            {
                //only two process with 1 pipe is supported at this time
                pos = charPtr - comArgs;
                strncpy(p1, comArgs, pos);
                p1[pos -1] = '\0';
                pos2 = strlen(comArgs) - pos -1;
                strncpy(p2, comArgs+pos+2, strlen(comArgs) - pos -1);
                p2[pos2] = '\0';
                getPipe(p1, p2);
            }
            else
                printf("Only two processes for the pipe, please!\n");

            count = 0;

            continue;
        }

        //tokenize the command and arguments
        argc = getCommand(comArgs, com);

        if (argc > 2)
        {
            printf("Only one argument, please!\n");
            cleanup(comArgs, com, &count);
            continue;
        }

        //executing the command in the child process
        if ((pid = fork()) == 0)    //child for executing
        {
            if (execvp(com[0], com) == -1)
                perror("File type need to be executable");
            exit(-1);
        }
        else    //parent for waiting
        {
            wait(NULL);
            cleanup(comArgs, com, &count);
        }
    }
    while (!done);
}

//reset the command and arguments and counter
void cleanup(char * cargs, char* coms[], int *count)
{
    int i;

    for (i = 0; i < STR_LENGTH; i++)
    {
        cargs[i] = '\0';
        if (i < COMMAND_LEN && coms[i] != NULL)
            free(coms[i]);
    }
    *count = 0;
}

//set up the pipes - only two processes
void getPipe(const char *lhs, const char* rhs)
{
    int fds[2];
    pid_t pid1, pid2;
    char *comL[COMMAND_LEN] = { NULL }, *comR[COMMAND_LEN] = { NULL };
    int argcL, argcR;

    argcL = getCommand(lhs, comL);
    argcR = getCommand(rhs, comR);

    if (argcL > 2 || argcR > 2)
    {
        printf("Only one argument per executable, please!\n");
        return;
    }

    if (pipe(fds) == -1)
    {
        perror("Can not create pipes!");
        exit(-1);
    }

    if ((pid1 = fork()) == 0)   //directing first child's stdout
    {
        close(fds[0]);
        dup2(fds[1], STDOUT_FILENO);
        close(fds[1]);
        if (execvp(comL[0], comL) == -1)
        {
            perror("Pipe out failed");
            exit(-1);
        }

    }
    else if ((pid2 = fork()) == 0)  //to second child's stdin
    {
        dup2(fds[0], STDIN_FILENO);
        close(fds[0]);
        close(fds[1]);
        if (execvp(comR[0], comR) == -1)
        {
            perror("Pipe in failed");
            exit(-1);
        }

    }
    else    //parent process is waiting
    {
        close(fds[0]);
        close(fds[1]);
        waitpid(pid1, NULL, 0);
        waitpid(pid2, NULL, 0);
    }
}

//tokenize the command and arguments
int getCommand(const char *comArgs, char *com[])
{
    char  *tok, *tmpStr;
    const char deli[] = " \t";
    int i = 0, argc = 0;


    tmpStr = strdup(comArgs);
    tok = strtok(tmpStr, deli);
    while (tok != NULL)
    {
        com[i++] = strdup(tok);
        tok = strtok(NULL, deli);
    }

    argc = i;

    for (; i < COMMAND_LEN; i++)
        com[i] = NULL;

    free(tmpStr);

    return argc;

}
