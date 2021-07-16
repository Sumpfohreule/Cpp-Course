#ifndef SHORTEST_PATH_H
#define SHORTEST_PATH_H

#include "../graph/graph.h"
#include "../priority_queue/priority_queue.h"

class ShortestPath {
    private:
        Graph g;
        std::vector<int> distances;
        void CalculateDistances(int);
    public:
        ShortestPath(Graph g, int start) : g(g) {
            this->CalculateDistances(start);
        };
        std::vector<int> Distances();
        float AverageDistance();
};

#endif
