//    Dong Lin
//    cssc4206
//    redid: 827228799
#ifndef MEMBESTFIT_H
#define MEMBESTFIT_H
#include "memmgr.h"

class membestfit :
    public MEMMGR
{
public:
    int allocate_mem(int process_id, int num_units) override;

};

#endif
