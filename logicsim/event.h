#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

typedef struct EventLess {
    bool operator()(const Event* lhs, const Event* rhs) const{
        return lhs->time < rhs->time;
    }
        //write the operator() required to make this a functor that compares Events by time
} EventLess;
	
#endif
