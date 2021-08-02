/*  Dong Lin
    cssc4206
    redid: 827228799
*/
#ifndef MSH_H_INCLUDED
#define MSH_H_INCLUDED

#define _SVID_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>

#define STR_LENGTH 120
#define PROMPT_LEN 15
#define COMMAND_LEN 20

char prompt[PROMPT_LEN];

void init();
void startShell();
bool checkExit(char * str);
int getCommand(const char *comArgs, char* com[]);
void getPipe(const char *LHS, const char * RHS);
void cleanup(char * cargs, char* coms[], int *count);


#endif // MSH_H_INCLUDED
