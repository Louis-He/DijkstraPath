#include "pathMain.h"

std::priority_queue<intersection*, std::vector<intersection*>,  Compare> intersectionQueue;

void initializedataStructure(){
    intersections.push_back(intersection(500, 400, 0));  // 0
    intersections.push_back(intersection(600, 450, 1));  
    intersections.push_back(intersection(550, 450, 2));
    intersections.push_back(intersection(400, 300, 3));
    intersections.push_back(intersection(200, 350, 4));
    intersections.push_back(intersection(800, 550, 5));
    intersections.push_back(intersection(200, 700, 6));
    intersections.push_back(intersection(350, 660, 7));
    intersections.push_back(intersection(600, 200, 8));
    intersections.push_back(intersection(750, 260, 9));  // 9

    intersectionConnections.resize(14);
    streets.resize(14);
    for(int  i =0; i < streets.size(); i++){
        streets[i].resize(14);
    }

    addStreets(4, 3, 10);  // 0
    addStreets(3, 8, 20);
    addStreets(8, 9, 5);
    addStreets(9, 1, 8);
    addStreets(1, 2, 12);
    addStreets(0, 8, 19);
    addStreets(0, 3, 3);
    addStreets(2, 7, 26);
    addStreets(7, 1, 9);
    addStreets(6, 7, 2);
    addStreets(6, 3, 34);
    addStreets(6, 0, 8);
    addStreets(2, 0, 14);
    addStreets(2, 8, 32);  //  13

    initializeDijkstra();
}

void addStreets(unsigned start, unsigned dest, double time){
    streets[start][dest] = streetSegment(start, dest, time);
    streets[dest][start] = streetSegment(dest, start, time);
    intersectionConnections[start].push_back(dest);
    intersectionConnections[dest].push_back(start);
}

void initializeDijkstra(){
    for(int i = 0; i < intersections.size(); i++){
        intersections[i].isVisited = false;
        intersections[i].isInQueue = false;
        intersections[i].isDest = false;
        intersections[i].parent = -2;
        intersections[i].time = INT32_MAX;
    }
}

void DijkstraStart(unsigned id, unsigned dest){
    intersections[id].parent = -1;
    intersections[id].time = 0;
    intersections[id].isSrc = true;

    intersections[dest].isDest = true;

    intersectionQueue.push(&intersections[id]);
}

void oneStepDijkstra(){
    intersection* leastTime = intersectionQueue.top();
    intersectionQueue.pop();
    leastTime->isVisited = true;
    unsigned id = leastTime->id;

    if(leastTime->isDest){
        return;
    }

    // push first front wave
    for(int i = 0; i < intersectionConnections[id].size(); i++){
        unsigned segEnd = intersectionConnections[id][i];
        if(intersections[segEnd].isVisited){
            continue;
        }

        if(intersections[segEnd].parent == -2){
            intersections[segEnd].parent = id;
            intersections[segEnd].time = leastTime->time + streets[id][segEnd].time;
        }else{
            if(leastTime->time + streets[id][segEnd].time < intersections[segEnd].time){
                intersections[segEnd].time = leastTime->time + streets[id][segEnd].time;
                intersections[segEnd].parent = id;
            }
        }

        if(! intersections[segEnd].isInQueue){
            intersectionQueue.push(&(intersections[segEnd]));
        }
        intersections[segEnd].isInQueue = true;
    }
}