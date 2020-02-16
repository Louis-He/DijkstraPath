#ifndef PATH_H
#define PATH_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class intersection{
public:
    unsigned x;
    unsigned y;
    unsigned id;

    bool isVisited;
    bool isInQueue;
    bool isSrc;
    bool isDest;
    unsigned time;
    unsigned parent;

    intersection(unsigned _x, unsigned _y, unsigned _id);
};

class streetSegment{
public:
    unsigned from;
    unsigned to;
    
    double time;

    streetSegment();
    streetSegment(unsigned _from, unsigned _to, double _time);
};

extern std::vector<intersection> intersections;
extern std::vector<std::vector<unsigned>> intersectionConnections;
extern std::vector<std::vector<streetSegment>> streets;

#endif