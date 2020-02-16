#ifndef PATH_MAIN_H
#define PATH_MAIN_H

#include "path.h"
#include <queue>
#include <functional>

class Compare
{
public:
    bool operator() (intersection* intersection1, intersection* intersection2)
    {
        return intersection1->time > intersection2->time;
    }
};

extern std::priority_queue<intersection*, std::vector<intersection*>,  Compare> intersectionQueue;

void initializedataStructure();

void addStreets(unsigned start, unsigned dest, double time);
void initializeDijkstra();
void DijkstraStart(unsigned id, unsigned dest);
void oneStepDijkstra();

#endif