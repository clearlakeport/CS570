//    Dong Lin
//    cssc4206
//    redid: 827228799
#ifndef MEMMGR_H
#define MEMMGR_H
#include <bits/stdc++.h>
#include "dll.h"

#define TOTALMEM 256000
#define BLOCKSIZE 2000
#define HID INT_MIN //process id for holes
#define FRAG 2 //frag size 1 or 2

//memory blocks
struct block
{
    int pid; //process id
    int length; //number of 2K blocks
};

typedef struct block block;

class MEMMGR
{
protected:
    DblyLinkedList<block> memBlks;

public:
    MEMMGR();
    virtual int allocate_mem(int process_id, int num_units);
    int deallocate_mem(int process_id);
    int fragment_count();
};

#endif
