#ifndef GRAPH_H
#define GRAPH_H

#include "edge/edge.h"
#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>

class Graph {
    private:
        std::vector<int> nodes;
        std::map<Edge, int> edges;
        bool EdgeHasNode(Edge, int);
        int GetConnectedNode(Edge, int);
    public:
        Graph();
        Graph(int);
        void AddRandomEdges(float);

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
