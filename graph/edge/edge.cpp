#include "edge.h"

using namespace std;

void Edge::OrderNodes() {
    if (this->node_1 > this->node_2) {
        swap(this->node_1, this->node_2);
    }
}

int Edge::node1() {
    return this->node_1;
}

int Edge::node2() {
    return this->node_2;
}

int Edge::get_weight() {
    return this->weight;
}

bool Edge::ConnectsWith(int node) {
    return this->node_1 == node || this->node_2 == node;
}

int Edge::GetOtherNode(int node) {
    if (this->node_1 == node) {
        return this->node_2;
    } else if (this->node_2 == node) {
        return this->node_1;
    } else {
        return -1;
    }
}

