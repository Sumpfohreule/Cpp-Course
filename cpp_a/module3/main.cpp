#include "graph/graph.h"
#include "shortest_path/shortest_path.h"
#include <iostream>

using namespace std;

const int kNodeCount = 50;
const int kWeightMin = 1.0;
const int kWeightMax = 10.0;
const float kLowDensity = 0.2;
const float kHighDensity = 0.4;
const int kStartNode = 0;

void PrintDistances(vector<int>, int);

int main() {
    Graph low_density_graph = Graph(50);
    low_density_graph.AddRandomEdges(kLowDensity, kWeightMin, kWeightMax);
    vector<int> dist_low = ShortestPath(low_density_graph).Distances(kStartNode);
    PrintDistances(dist_low, 20);

    Graph high_density_graph = Graph(50);
    high_density_graph.AddRandomEdges(kHighDensity, kWeightMin, kWeightMax);
    vector<int> dist_high = ShortestPath(high_density_graph).Distances(kStartNode);
    PrintDistances(dist_high, 40);

    return 0;
}

void PrintDistances(vector<int> distances, int density) {
    cout << "Distances from node 0 to n (Node: Distance)" << endl;
    cout << density << "% density graph";
    for (int i = 0; i < distances.size(); i++) {
        if (i % 10 == 0) {
            cout << endl;
        }
        cout << "\t" << i << ": " << distances[i];
    }
    cout << endl << endl;
}
