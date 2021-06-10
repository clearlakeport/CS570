#include "bots.h"

char* even_quote = "\"Controlling complexity is the essence of computer programming.\" -Brian Kernigan";
char* odd_quote = "\"Computer science is no more about computers than astronomy is about telescopes.\" -Edsger Dijkstra";

// create the semaphore and join with the main process
// print the initial output
void init()
{
    //output the process ID
    pid_t pid;
    char buff[20];

    printf("Bots\n");

    pid = getpid();
    sprintf(buff, "Process ID: %d", (int) pid);

    makeChatFile(FNAME, "w", buff);

    sem_init(&FLAG, 0, 1); // semaphore is shared within the process
}

//create 7 thread
void start()
{
    int i;

    // create the threads with thread IDs
    for(i = 0; i < NUM_THREADS; i++)
    {
        thd_id[i] = malloc(sizeof(*thd_id[i]));
        *thd_id[i] = i;
        if (pthread_create(&thd[i], NULL, &chatMesg, thd_id[i]) != 0)
        {
            perror("Failed to create thread\n");
            exit(-1);
        }
        else
        {
            printf("Creating thread, in main(): %d\n", i + 1);
        }

    }

    // join, wait the threads for threads to finish
    for (i = 0; i < NUM_THREADS; i++)
    {
        if (pthread_join(thd[i], NULL) != 0)
        {
            perror("Failed to join");
            exit(-1);
        }
    }
}

//write the chat text
void makeChatFile(char* fname, char* mode, char* str)
{
    FILE* fp;
    static int lineNum = 1;

    fp = fopen(fname, mode);
    if (fp == NULL)
    {
        perror("Can not open output file!\n");
        exit(-1);
    }
    fprintf(fp, "%d %s\r\n", lineNum++, str);
    fclose(fp);
}

//function pointer for the threads
void* chatMesg(void* args)
{
    bool done = false;
    int count = 0, thdID, sleepTime;
    char buffer[120];


    thdID = *(int *)args;   //get the thread ID (0 based)
    //even threads wait for 2 second, odd threads wait for 3 sec
    if ((thdID + 1) % 2 == 0)
    {
        sprintf(buffer, "Thread ID %d: %s", thdID + 1, even_quote); //even thread ID
        sleepTime = 2;
    }
    else
    {
        sprintf(buffer, "Thread ID %d: %s", thdID + 1, odd_quote);  //odd Thread ID
        sleepTime = 3;
    }

    //write to chat file once
    writeToChat(buffer, thdID, sleepTime);

    //repeat 7 more times to write to chat file
    while (!done)
    {
        count++;
        writeToChat(buffer, thdID, sleepTime);

        if (count >= 7)
            done = true;
    }
    pthread_exit(NULL);

}

//output the text msg to chat file using semaphore in critical section
void writeToChat(char* buffer, const int thdID, const int sleepTime)
{
    printf("Thread %d is running\n", thdID+1);
    sleep(sleepTime);

    //wait
    sem_wait(&FLAG);

    //critical section
    makeChatFile(FNAME, "a", buffer);

    //signal
    sem_post(&FLAG);
}

//free the system resources
void release()
{
    int i;

    for (i = 0; i < NUM_THREADS; i++)
    {
        free(thd_id[i]);
    }

    sem_destroy(&FLAG);

    printf("Good Bye!\n");
}
