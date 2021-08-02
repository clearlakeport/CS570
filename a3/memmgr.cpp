//    Dong Lin
//    cssc4206
//    redid: 827228799
#include "memmgr.h"

MEMMGR::MEMMGR()
{
    block first;

    first.length = TOTALMEM / BLOCKSIZE;
    first.pid = HID;

    memBlks.addNodeFront(first);
}

int MEMMGR::allocate_mem(int process_id, int num_units)
{
    Node<block>* blkPtr;
    int traversed = 0;
    block tBlock;

    tBlock.pid = process_id;
    tBlock.length = num_units;
    if (memBlks.find(tBlock))
    {
        return 0;
    }

    blkPtr = memBlks.getHead();

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

                int newLen = blkPtr->Data.length - num_units;
                blkPtr->Data.length = newLen;

                block tmpBlk;
                tmpBlk.pid = process_id;
                tmpBlk.length = num_units;

                memBlks.insertBefore(blkPtr, tmpBlk);

                return traversed;
            }
            else
                blkPtr = blkPtr->Next; // block too small, try next
        }
        else
        {
            blkPtr = blkPtr->Next;  // block is filled
        }
    }

    return -1;
}



int MEMMGR::deallocate_mem(int process_id)
{
    Node<block>* tPtr;

    tPtr = memBlks.getHead();

    while (tPtr != NULL)
    {
        if (tPtr->Data.pid == process_id)
        {
            tPtr->Data.pid = HID;
            if (((tPtr->Prev != NULL) && (tPtr->Prev->Data.pid == HID)) && ((tPtr->Next != NULL) && (tPtr->Next->Data.pid == HID)))
            {

                tPtr->Prev->Data.length += tPtr->Data.length + tPtr->Next->Data.length;
                memBlks.deleteNode(tPtr->Next);
                memBlks.deleteNode(tPtr);
            }
            else if ((tPtr->Prev != NULL) && (tPtr->Prev->Data.pid == HID))
            {
                tPtr->Prev->Data.length += tPtr->Data.length;
                memBlks.deleteNode(tPtr);
            }
            else if ((tPtr->Next != NULL) && (tPtr->Next->Data.pid == HID))
            {
                tPtr->Next->Data.length += tPtr->Data.length;
                memBlks.deleteNode(tPtr);
            }
            else
                return 1;

            return 1;
        }
        else
            tPtr = tPtr->Next;

    }

    return -1;

}


int MEMMGR::fragment_count()
{
    Node<block>* nb;
    int fragCount = 0;

    memBlks.reset();

    nb = memBlks.nextNode();
    while (nb != NULL)
    {
        if ((nb->Data.pid == HID) && (nb->Data.length <= FRAG))
            fragCount++;
        nb = memBlks.nextNode();
    }

    return fragCount;
}

