#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>

class Edge {
    private:
        int node_1;
        int node_2;
        int weight;

        void OrderNodes();
    public:
        Edge(int node_1, int node_2, int weight) : node_1(node_1), node_2(node_2), weight(weight) {
            this->OrderNodes();
        };
        Edge(int node_1, int node_2) : node_1(node_1), node_2(node_2) {
            this->OrderNodes();
        };

        int node1();
        int node2();
        bool ConnectsWith(int);
        int GetOtherNode(int);
        friend bool operator<(const Edge& left, const Edge& right);
        friend bool operator>(const Edge& left, const Edge& right);
        friend bool operator==(const Edge& left, const Edge& right);
        friend bool operator!=(const Edge& left, const Edge& right);
};

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
        void DeleteEdge(int, int);
        bool Adjacent(int, int);
        std::vector<int> Neighbors(int);
        void SetEdgeValue(int, int, int);
        int GetEdgeValue(int, int);

        int V();
        int E();
};

#endif
