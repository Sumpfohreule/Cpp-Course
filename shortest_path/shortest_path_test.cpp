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
    EXPECT_EQ(path.Distances(1), vec2);
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

TEST(Distances, CanBeDifferentWithOtherStart) {
    Graph g = Graph(5);
    g.AddEdge(0, 1, 1);
    g.AddEdge(1, 2, 1);
    g.AddEdge(1, 4, 2);
    g.AddEdge(1, 3, 1);
    g.AddEdge(3, 4, 3);


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
