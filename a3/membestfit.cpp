//    Dong Lin
//    cssc4206
//    redid: 827228799
#include "membestfit.h"

int membestfit::allocate_mem(int process_id, int num_units)
{
    Node<block>* blkPtr, *minPtr = NULL;
    int traversed = 0;
    block tBlk;
    int Min = 0;
    bool found = false;


    tBlk.pid = process_id;
    tBlk.length = num_units;
    //if the process is already in memory, then return
    if (memBlks.find(tBlk))
    {
        return 0;
    }

    memBlks.reset();
    blkPtr = memBlks.nextNode();

    while (blkPtr)
    {
        traversed++;

        if (blkPtr->Data.pid == HID)
        {
            if (blkPtr->Data.length == num_units)
            {
                blkPtr->Data.pid = process_id;
                return traversed;
            }
            else if (blkPtr->Data.length > num_units)
            {
                if (!found)
                {
                    Min = blkPtr->Data.length;
                    minPtr = blkPtr;
                    found = true;
                }
                else
                {
                    if (blkPtr->Data.length < Min)
                    {
                        Min = blkPtr->Data.length;
                        minPtr = blkPtr;
                    }
                }
                blkPtr = blkPtr->Next;
            }
            else
                blkPtr = blkPtr->Next; // block too small, try next
        }
        else
        {
            blkPtr = blkPtr->Next;  // block is filled
        }
    }

    if (found)
    {
        block tmpBlk;
        tmpBlk.pid = process_id;
        tmpBlk.length = num_units;
        minPtr->Data.length -= num_units;

        memBlks.insertBefore(minPtr, tmpBlk);

        return traversed;
    }

    return -1;
}

