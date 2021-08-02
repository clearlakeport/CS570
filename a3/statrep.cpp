//    Dong Lin
//    cssc4206
//    redid: 827228799
#include "statrep.h"

using namespace std;

statrep::statrep()
{
    reset();

}
void statrep::reset()
{
    allocFail = 0;
    deallocFail = 0;
    totAllocReq = 0;
    fragCount = 0;
    numAllocs = 0;
    allocRslt = 0;
    totTraversed = 0;
    numReq = 0;
    tPuVec.clear();
}

void statrep::firstFit()
{
    reset();

    MEMMGR memAllocMthd;

    tPuVec = reqGen.getPidUnits();  //generate pid and mem units req

    while (numReq < ATTEMPTS)
    {
        for (auto itr = tPuVec.begin(); itr != tPuVec.end(); itr++)
        {
            tpu = *itr;

            allocRslt = memAllocMthd.allocate_mem(tpu.pid, tpu.units);
            if (allocRslt == -1)
            {
                allocFail++;
                fragCount += memAllocMthd.fragment_count();
                totAllocReq++;
                numReq++;
            }
            else if (allocRslt > 0)
            {
                totTraversed += allocRslt;
                numAllocs++;
                totAllocReq++;
                numReq++;
            }

        }

        //randomize the pid/units vector
        random_shuffle(tPuVec.begin(), tPuVec.end());

        //deallocate random number of nodes
        int numDealloc = tPuVec.size();
        if (numDealloc != 0)
            numDealloc = rand() % tPuVec.size();

        for (int i = 0; i < numDealloc; i++)
        {
            tpu = tPuVec.back();
            tPuVec.pop_back();
            if (memAllocMthd.deallocate_mem(tpu.pid) == -1)
                deallocFail++;
            numReq++;
        }

        vector<pu> tVec;
        tVec = reqGen.getPidUnits();
        tPuVec.insert(tPuVec.end(), tVec.begin(), tVec.end());

    }

    cout << ">> First Fit Memory Allocation and Deallocation: <<" << endl;
    printFrag();
    printAvgAlloc();
    printReqDenied();
}


void statrep::printFrag()
{

    cout << "Frag Count: " << fragCount << endl;
    cout << "Num of failed allocation: " << allocFail << endl;
    cout << "Average external fragments: ";
    cout << fixed << setprecision(2) << (float)fragCount / (float)allocFail << endl << endl;
}
void statrep::printAvgAlloc()
{
    cout << "Total Traverse: " << totTraversed << endl;
    cout << "Num of allocation: " << numAllocs << endl;
    cout << "Average allocation time: ";
    cout << fixed << setprecision(2) << (float)totTraversed / (float)numAllocs << endl << endl;
}

void statrep::printReqDenied()
{
    cout << "Allocation Fail: " << allocFail << endl;
    cout << "Total Req: " << totAllocReq << endl;
    cout << "Percentage of allocation denied: ";
    cout << fixed << setprecision(3) << (float)allocFail / (float)totAllocReq * 100 << "%" << endl << endl;
}

void statrep::bestFit()
{
    reset();

    membestfit memAllocMthd;

    tPuVec = reqGen.getPidUnits();  //generate pid and mem units req

    while (numReq < ATTEMPTS)
    {
        for (auto itr = tPuVec.begin(); itr != tPuVec.end(); itr++)
        {
            tpu = *itr;

            allocRslt = memAllocMthd.allocate_mem(tpu.pid, tpu.units);
            if (allocRslt == -1)
            {
                allocFail++;
                fragCount += memAllocMthd.fragment_count();
                totAllocReq++;
                numReq++;
            }
            else if (allocRslt > 0)
            {
                totTraversed += allocRslt;
                numAllocs++;
                totAllocReq++;
                numReq++;
            }

        }

        //randomize the pid/units vector
        random_shuffle(tPuVec.begin(), tPuVec.end());

        //deallocate random number of nodes
        int numDealloc = 0;
        if (tPuVec.size() != 0)
            numDealloc = rand() % tPuVec.size();

        for (int i = 0; i < numDealloc; i++)
        {
            tpu = tPuVec.back();
            tPuVec.pop_back();
            if (memAllocMthd.deallocate_mem(tpu.pid) == -1)
                deallocFail++;
            numReq++;
        }

        vector<pu> tVec;
        tVec = reqGen.getPidUnits();
        tPuVec.insert(tPuVec.end(), tVec.begin(), tVec.end());

    }

    cout << ">> Best Fit Memory Allocation and Deallocation: <<" << endl;
    printFrag();
    printAvgAlloc();
    printReqDenied();
}
