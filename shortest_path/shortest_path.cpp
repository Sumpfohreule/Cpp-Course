#include "shortest_path.h"
#include <bits/stdc++.h>

using namespace std;

std::vector<int> ShortestPath::Distances(int origin) {
    vector<int> dist(this->g.V(), INT_MAX);
    dist[origin] = 0;
    //vector<int> prev(this->g.V(), -1);
    PriorityQueue<int> queue = PriorityQueue<int>();

    for (int i = 0; i < this->g.V(); i++) {
        queue.Push(i, dist[i]);
    }

    cout << "WHILE START" << endl;
    while (queue.Size() > 0) {
        int u = queue.Pop();
        cout << "u: " << u << endl;
        vector<int> neighbors = this->g.Neighbors(u);
        
        cout << "FOR START" << endl;
        for (vector<int>::iterator v = neighbors.begin(); v != neighbors.end(); v++) {
            if (queue.Contains(*v)) {
                int alt = dist[u] + this->g.GetEdgeValue(u, *v);
                cout << "\tv: " << *v << " alt: " << alt << endl;
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
    return dist;
}

