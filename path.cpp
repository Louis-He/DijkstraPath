#include "path.h"

std::vector<intersection> intersections;
std::vector<std::vector<unsigned>> intersectionConnections;
std::vector<std::vector<streetSegment>> streets;

intersection::intersection(unsigned _x, unsigned _y, unsigned _id){
    x = _x;
    y = _y;
    id = _id;

    isVisited = false;
    isInQueue = false;
    isSrc = false;
    isDest = false;
    time = INT32_MAX;
    parent = -2;
}

streetSegment::streetSegment(){
    from = -1;
    to = -1;
    time = -1;
}


streetSegment::streetSegment(unsigned _from, unsigned _to, double _time){
    from = _from;
    to = _to;
    time = _time;
}