#include "gtest/gtest.h"
#include "../graph/graph.h"
#include "shortest_path.h"
using namespace std;

TEST(Path, NoPath) {
    Graph g = Graph(2);
    ShortestPath path = ShortestPath(g);
    vector<int> vec1{0, -1};
    vector<int> vec2{-1, 0};
    EXPECT_EQ(path.Distances(0), vec1);
}

TEST(Path, SinglePath) {
    Graph g = Graph(2);
    g.AddEdge(0, 1, 10);
    ShortestPath path = ShortestPath(g);
    vector<int> vec{0, 10};
    
    EXPECT_EQ(path.Distances(0), vec); 
}

TEST(Path, TwoEdgePath) {
    Graph g = Graph(3);
    g.AddEdge(0, 1, 5);
    g.AddEdge(1, 2, 3);
    ShortestPath path = ShortestPath(g);
    vector<int> vec{0, 5, 8};
    EXPECT_EQ(path.Distances(0), vec);
}

TEST(Path, SplitPath) {
    Graph g = Graph(3);
    g.AddEdge(0, 1, 5);
    g.AddEdge(0, 2, 10);
    ShortestPath path = ShortestPath(g);
    vector<int> vec{0, 5, 10};
    EXPECT_EQ(path.Distances(0), vec);
}

TEST(Path, MultipleNodesShorterThanDirect) {
    Graph g = Graph(3);
    g.AddEdge(0, 1, 10);
    g.AddEdge(0, 2, 2);
    g.AddEdge(2, 1, 2);
    ShortestPath path = ShortestPath(g);
    vector<int> vec{0, 4, 2};
    EXPECT_EQ(path.Distances(0), vec);
}

TEST(AverageDistance, OneEdge) {
    Graph g = Graph(2);
    g.AddEdge(0, 1, 10);
    ShortestPath path = ShortestPath(g);
    EXPECT_EQ(path.AverageDistance(), 10.0);
}

TEST(AverageDistance, TwoEdges) {
    Graph g = Graph(3);
    g.AddEdge(0, 1, 20);
    g.AddEdge(1, 2, 31);
    ShortestPath path = ShortestPath(g);
    EXPECT_EQ(path.AverageDistance(), 35.5);
}

TEST(AverageDistance, SingleNodeNotConnected) {
    Graph g = Graph(3);
    g.AddEdge(0, 1, 20);
    ShortestPath path = ShortestPath(g);
    EXPECT_EQ(path.AverageDistance(), 20.0);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
