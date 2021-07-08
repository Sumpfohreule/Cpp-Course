#include "edge.h"

using namespace std;

void Edge::OrderNodes() {
    if (this->node_1 > this->node_2) {
        swap(this->node_1, this->node_2);
    }
}

int Edge::node1() {
    return(this->node_1);
}

int Edge::node2() {
    return(this->node_2);
}

int Edge::get_weight() {
    return(this->weight);
}

bool Edge::ConnectsWith(int node) {
    return(this->node_1 == node || this->node_2 == node);
}

int Edge::GetOtherNode(int node) {
    if (this->node_1 == node) {
        return(this->node_2);
    } else if (this->node_2 == node) {
        return(this->node_1);
    } else {
        return(-1);
    }
}

bool operator<(const Edge& left, const Edge& right) {
    if (left.weight != right.weight) {
        return(left.weight < right.weight);
    } else if (left.node_1 != right.node_1) {
        return(left.node_1 < right.node_1);
    } else {
        return(left.node_2 < right.node_2);
    }
}

bool operator>(const Edge& left, const Edge& right) {
    return(right < left);
}

bool operator==(const Edge& left, const Edge& right) {
    return(!(left < right || right < left));
}

bool operator!=(const Edge& left, const Edge& right) {
    return(left < right || right < left);
}

