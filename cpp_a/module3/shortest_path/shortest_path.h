#ifndef SHORTEST_PATH_H
#define SHORTEST_PATH_H

#include "../graph/graph.h"
#include "../priority_queue/priority_queue.h"

class ShortestPath {
    private:
        Graph g;
    public:
        ShortestPath(Graph g) : g(g) {};
        std::vector<int> Distances(int);
};

#endif
