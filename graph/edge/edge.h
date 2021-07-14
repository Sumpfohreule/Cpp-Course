#ifndef EDGE_H
#define EDGE_H

#include <algorithm>

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

        int node1();
        int node2();
        int get_weight();
        bool ConnectsWith(int);
        int GetOtherNode(int);
};

#endif
