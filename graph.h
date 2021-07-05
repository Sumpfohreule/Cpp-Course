#ifndef GRAPH_H
#include <vector>
#include <map>

class Edge {
    private:
        int node_1;
        int node_2;
        int value;
    public:
        Edge(int, int, int);
        Edge(int, int);
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
