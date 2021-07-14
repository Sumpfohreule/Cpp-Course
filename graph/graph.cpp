#include "graph.h"

using namespace std;
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

vector<Edge>::iterator Graph::FindEdge(int node_1, int node_2) {
    if (node_1 > node_2) {
        swap(node_1, node_2);
    }
    for (vector<Edge>::iterator it = this->edges.begin(); it != this->edges.end(); it++) {
        if ((*it).node1() == node_1 && (*it).node2() == node_2) {
            return(it);
        }
    }
    return(this->edges.end());
}

void Graph::AddEdge(int node_1, int node_2) {
    this->AddEdge(node_1, node_2, -1);
}

void Graph::AddEdge(int node_1, int node_2, int weight) {
    if (!this->Adjacent(node_1, node_2)) {
        Edge edge = Edge(node_1, node_2, weight);
        this->edges.push_back(edge);
    }
}

void Graph::DeleteEdge(int node_1, int node_2) {
    vector<Edge>::iterator it = this->FindEdge(node_1, node_2);
    if (it != this->edges.end()) {
        this->edges.erase(it);
    }
}

bool Graph::Adjacent(int node_1, int node_2) {
    vector<Edge>::iterator it = this->FindEdge(node_1, node_2);
    if (it != this->edges.end()) {
        return(true);
    } else {
        return(false);
    }
}

vector<int> Graph::Neighbors(int node) {
    vector<int> neighbors;
    vector<Edge>::iterator it;
    for (it = this->edges.begin(); it != this->edges.end(); it++) {
        Edge edge = *it;
        if (edge.ConnectsWith(node)) {
            neighbors.push_back(edge.GetOtherNode(node));
        }
    }
    return(neighbors);
}

void Graph::SetEdgeValue(int node_1, int node_2, int value) {
    Edge lookup = Edge(node_1, node_2);
    vector<Edge>::iterator it = find(this->edges.begin(), this->edges.end(), lookup);
    *it = Edge(node_1, node_2, value);
}

int Graph::GetEdgeValue(int node_1, int node_2) {
    vector<Edge>::iterator it = this->FindEdge(node_1, node_2);
    if (it != this->edges.end()) {
        return((*it).get_weight());
    } else {
        return(-1);
    }
}


int Graph::V() {
    return(this->nodes.size());
}

int Graph::E() {
    return(this->edges.size());
}

