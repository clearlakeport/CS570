#ifndef BOTS_H_INCLUDED
#define BOTS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>


#define FNAME "QUOTE.txt"
#define NUM_THREADS 7

sem_t FLAG; //unmaed semaphore for the chat file
pthread_t thd[NUM_THREADS]; //thread handles
int* thd_id[NUM_THREADS];    //thread IDs
extern char* even_quote;
extern char* odd_quote;

void init();
void start();
void makeChatFile(char* fname, char* mode, char* str);
void writeToChat(char* buff, const int tid, const int st);
void* chatMesg(void* args);
void release();

#endif // BOTS_H_INCLUDED
