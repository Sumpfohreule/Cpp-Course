#include "graph.h"
#include "edge/edge.h"
#include <gtest/gtest.h>

using namespace std;

TEST(GraphV, ReturnZeroOnEmptyGraph) {
    Graph g = Graph();
	EXPECT_EQ(g.V(), 0);
}

TEST(GraphV, ReturnCountForVertices) {
    Graph g = Graph(10);
	EXPECT_EQ(g.V(), 10);
}

TEST(GraphAddEdge, ZeroEdges) {
    Graph g = Graph(10);
    EXPECT_EQ(g.E(), 0);
}

TEST(GraphAddEdge, MultipleEdges) {
    Graph g = Graph(10);
    g.AddEdge(0, 1, 4);
    g.AddEdge(1, 2, 4);
    g.AddEdge(2, 3, 4);
    EXPECT_EQ(g.E(), 3);
}

TEST(GraphAddEdge, AddingSameEdgeDifferentWeights) {
    Graph g = Graph(10);
    g.AddEdge(0, 1, 5);
    g.AddEdge(0, 1, 9);
    EXPECT_EQ(g.E(), 1);
}

TEST(GraphAdjacent, NoEdgeBetweenNodes) {
    Graph g = Graph(10);
    EXPECT_FALSE(g.Adjacent(1, 5));
}

TEST(GraphAdjacent, EdgeBetweenNodes) {
    Graph g = Graph(10);
    g.AddEdge(1, 5, 4);
    EXPECT_TRUE(g.Adjacent(1, 5));
}

TEST(GraphEdgeValue, GetEdgeValue) {
    Graph g = Graph(10);
    g.AddEdge(1, 5, 4);
    EXPECT_EQ(g.GetEdgeValue(1,5), 4);
    EXPECT_EQ(g.GetEdgeValue(5,1), 4);
}

TEST(GraphEdgeValue, SetEdgeValue) {
    Graph g = Graph(10);
    g.AddEdge(1, 5, 4);
    g.SetEdgeValue(1, 5, 6);
    EXPECT_EQ(g.GetEdgeValue(1,5), 6);
}

TEST(GraphEdgeValue, SetEdgeValueReverse) {
    Graph g = Graph(10);
    g.AddEdge(1, 5, 4);
    g.SetEdgeValue(5, 1, 6);
    EXPECT_EQ(g.GetEdgeValue(1, 5), 6);
}

TEST(GraphDeleteEdge, DeleteExisting) {
    Graph g = Graph(2);
    g.AddEdge(0, 1, 4);
    g.DeleteEdge(0, 1);
    EXPECT_EQ(g.E(), 0);
}

TEST(GraphDeleteEdge, DeleteEdgeWithWeight) {
    Graph g = Graph(2);
    g.AddEdge(0, 1, 5);
    g.DeleteEdge(0, 1);
    EXPECT_EQ(g.E(), 0);
}

TEST(EdgeConstructor, NodeOrderDoesNotMatter) {
    Edge small_big = Edge(3, 10, -1);
    Edge big_small = Edge(10, 3, -1);
    EXPECT_EQ(small_big.node1(), big_small.node1());
    EXPECT_EQ(small_big.node2(), big_small.node2());
}

TEST(NodeNeighbors, NodeWithoutNeighbors) {
    Graph g = Graph(10);
    vector<int> empty_vector;
    EXPECT_EQ(g.Neighbors(3), empty_vector);
}

TEST(NodeNeighbors, NodeWithMultipleNeighbors) {
    Graph g = Graph(10);
    g.AddEdge(1, 3, 4);
    g.AddEdge(1, 5, 4);
    g.AddEdge(1, 9, 4);
    vector<int> neighbor_nodes;
    neighbor_nodes.push_back(3);
    neighbor_nodes.push_back(5);
    neighbor_nodes.push_back(9);
    EXPECT_EQ(g.Neighbors(1), neighbor_nodes);
}

TEST(RandomEdges, CreateGraphWithZeroEdges) {
    Graph g = Graph(100);
    g.AddRandomEdges(0.0, 1.0, 10.0);
    EXPECT_EQ(g.E(), 0);
}

TEST(RandomEdges, CreateGraphWith10Percent) {
    Graph g = Graph(50);
    g.AddRandomEdges(0.1, 1.0, 10.0);
    EXPECT_TRUE(g.E() > 72.5 && g.E() < 172.5);
}

TEST(RandomEdges, CreateGraphWith50Percent) {
    Graph g = Graph(50);
    g.AddRandomEdges(0.5, 1.0, 10.0);
    EXPECT_TRUE(g.E() > 562.5 && g.E() < 662.5) ;
}

TEST(RandomEdges, CreateGraphWith100Percent) {
    Graph g = Graph(50);
    g.AddRandomEdges(1.0, 1.0, 10.0);
    EXPECT_EQ(g.E(), 1225);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
