#include "graph.h"

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
    if (left.node_1 != right.node_1) {
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

Graph::Graph() {}

Graph::Graph(int node_count) {
    vector<int> nodes;
    nodes.reserve(node_count);

    for (int i = 0; i < node_count; i++) {
        nodes.push_back(i);
    }
    this->nodes = nodes;
}

void Graph::AddRandomEdges(float density) {
    srand(time(nullptr));
    for (int i = 0; i < this->V(); i++) {
        for (int j = i + 1; j < this->V(); j++) {
            if (i != j && (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) < density) {
                this->AddEdge(i, j);
            }
        }
    }
}

bool Graph::EdgeHasNode(Edge edge, int node) {
    return(edge.node1() == node || edge.node2() == node);
}

int Graph::GetConnectedNode(Edge edge, int node) {
    if (edge.node1() == node) {
        return(edge.node2());
    } else if (edge.node2() == node) {
        return(edge.node1());
    } else {
        return(-1);
    }
}

void Graph::AddEdge(int node_1, int node_2) {
    Edge edge = Edge(node_1, node_2);
    this->edges.insert(pair<Edge, int>(edge, -1));
}

void Graph::DeleteEdge(int node_1, int node_2) {
    Edge delete_edge = Edge(node_1, node_2);
    this->edges.erase(delete_edge);
}

bool Graph::Adjacent(int node_1, int node_2) {
    Edge lookup = Edge(node_1, node_2);
    map<Edge, int>::iterator it = this->edges.find(lookup);
    if (it != this->edges.end()) {
        return(true);
    } else {
        return(false);
    }
}

vector<int> Graph::Neighbors(int node) {
    vector<int> neighbors;
    map<Edge, int>::iterator it;
    for (it = this->edges.begin(); it != this->edges.end(); it++) {
        Edge edge = it->first;
        if (edge.ConnectsWith(node)) {
            neighbors.push_back(edge.GetOtherNode(node));
        }
    }
    return(neighbors);
}



void Graph::SetEdgeValue(int node_1, int node_2, int value) {
    Edge lookup = Edge(node_1, node_2);
    this->edges.at(lookup) = value;
}

int Graph::GetEdgeValue(int node_1, int node_2) {
    Edge lookup = Edge(node_1, node_2);
    return(this->edges.at(lookup));
}


int Graph::V() {
    return(this->nodes.size());
}

int Graph::E() {
    return(this->edges.size());
}
