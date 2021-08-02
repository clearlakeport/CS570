//    Dong Lin
//    cssc4206
//    redid: 827228799
#include "reqgen.h"

using namespace std;

int reqgen::setProcID()
{
    procID++;
    return procID;
}

int reqgen::setRegUnits()
{
    regUnits = rand() % (UNIT_MAX - UNIT_MIN + 1) + UNIT_MIN;   //mod 8 + 3 for 3 to 10 units

    return regUnits;
}

vector<pu> reqgen::getPidUnits()
{
    int numReq;
    pu tPu;
    vector<pu> puVec;

    numReq = rand() % INIT_NUM_PROC;

    for (int i = 0; i < numReq; i++)
    {
        tPu.pid = setProcID();
        tPu.units = setRegUnits();

        puVec.push_back(tPu);
    }

    return puVec;
}
