//    Dong Lin
//    cssc4206
//    redid: 827228799
#ifndef STATREP_H
#define STATREP_H

#include <iostream>
#include <iomanip>
#include <string>
#include "reqgen.h"
#include "memmgr.h"
#include "membestfit.h"

#define ATTEMPTS 10000

class statrep
{
public:
    statrep();
    void reset();
    void firstFit();
    void bestFit();
    void printFrag();
    void printAvgAlloc();
    void printReqDenied();

private:
    reqgen reqGen;   //random request generator for process
    vector<pu> tPuVec;   //vector holding for proc id and units allocated
    pu tpu;  //struct for pid and units req'd
    int allocFail, deallocFail, totAllocReq, fragCount;
    int numAllocs, allocRslt, totTraversed;
    int numReq;

};


#endif
