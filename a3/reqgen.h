//    Dong Lin
//    cssc4206
//    redid: 827228799
#ifndef REQGEN_H
#define REGGEN_H
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <vector>

#define UNIT_MAX 10
#define UNIT_MIN 3
#define INIT_NUM_PROC 10


struct Proc
{
    int pid;
    int units;
};

typedef struct Proc pu;

class reqgen
{
private:
    int procID;
    int regUnits;
    int setRegUnits();
    int setProcID();

public:
    reqgen()
    {
        procID = 0;
        regUnits = 0;
        srand((unsigned)time(NULL));
    }

    std::vector<pu> getPidUnits();

};


#endif // !REQGEN_H


