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
        ShortestPath(Graph g) : g(g) {
            this->CalculateDistances(0);
        };
        std::vector<int> Distances(int);
        float AverageDistance();
};

#endif
