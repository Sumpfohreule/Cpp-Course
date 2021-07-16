#include "shortest_path.h"
#include <bits/stdc++.h>

using namespace std;

std::vector<int> ShortestPath::Distances() {
    return this->distances;
}

float ShortestPath::AverageDistance() {
    vector<int> dist = this->distances;
    float no_path_count = 0;
    for (vector<int>::iterator it = dist.begin(); it != dist.end(); it++) {
        if (*it == -1) {
            no_path_count++;
        }
    }
    float sum = std::accumulate(dist.begin(), dist.end(), 0) + static_cast<float>(no_path_count);
    return sum / static_cast<float>((dist.size() - no_path_count - 1));
}

void ShortestPath::CalculateDistances(int origin) {
    vector<int> dist(this->g.V(), INT_MAX);
    dist[origin] = 0;
    //vector<int> prev(this->g.V(), -1);
    PriorityQueue<int> queue = PriorityQueue<int>();

    for (int i = 0; i < this->g.V(); i++) {
        queue.Push(i, dist[i]);
    }

    while (queue.Size() > 0) {
        int u = queue.Pop();
        vector<int> neighbors = this->g.Neighbors(u);
        
        for (vector<int>::iterator v = neighbors.begin(); v != neighbors.end(); v++) {
            if (queue.Contains(*v)) {
                int alt = dist[u] + this->g.GetEdgeValue(u, *v);
                if (alt < dist[*v]) {
                    dist[*v] = alt;
                    queue.SetPriority(*v, alt);
                    //prev[*v] = u;
                }
            }
        }
    }
    for (vector<int>::iterator it = dist.begin(); it != dist.end(); it++) {
        if (*it == INT_MAX) {
            *it = -1;
        }
    }
    this->distances = dist;
}
