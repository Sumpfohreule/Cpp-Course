#ifndef GRAPH_H
#define GRAPH_H

#include "edge/edge.h"
#include <vector>
#include <cstdlib>
#include <ctime>

class Graph {
    private:
        std::vector<int> nodes;
        std::vector<Edge> edges;

        float Random(float, float);
        std::vector<Edge>::iterator FindEdge(int, int);
    public:
        Graph();
        Graph(int);
        void AddRandomEdges(float, float, float);

        void AddEdge(int, int);
        void AddEdge(int, int, int);
        void DeleteEdge(int, int);
        bool Adjacent(int, int);
        std::vector<int> Neighbors(int);
        void SetEdgeValue(int, int, int);
        int GetEdgeValue(int, int);

        int V();
        int E();
};

#endif
