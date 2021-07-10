#include "gtest/gtest.h"
#include "priority_queue.h"
#include "../graph/edge/edge.h"
#include <ctime>
#include <vector>

TEST(Priorities, LessThan) {
    Priority p1 = Priority("D", 1);
    Priority p2 = Priority("A", 10);
    EXPECT_TRUE(p1 < p2);
}

TEST(Priorities, LargerThan) {
    Priority p1 = Priority("D", 1);
    Priority p2 = Priority("A", 10);
    EXPECT_TRUE(p2 > p1);
}

TEST(Priorities, Equals) {
    Priority p1 = Priority("D", 10);
    Priority p2 = Priority("A", 10);
    EXPECT_TRUE(p1 == p2);
}

TEST(Priorities, EqualsNot) {
    Priority p1 = Priority("D", 1);
    Priority p2 = Priority("A", 10);
    EXPECT_TRUE(p1 != p2);
}

TEST(Contains, SingleElement) {
    PriorityQueue<int> queue = PriorityQueue<int>();
    queue.Push(10);
    EXPECT_TRUE(queue.Contains(10));
    EXPECT_FALSE(queue.Contains(77));
}

TEST(Contains, MultipleElements) {
    PriorityQueue<int> queue = PriorityQueue<int>();
    queue.Push(10);
    queue.Push(20);
    queue.Push(30);
    EXPECT_FALSE(queue.Contains(15));
    EXPECT_TRUE(queue.Contains(10));
    EXPECT_TRUE(queue.Contains(20));
    EXPECT_TRUE(queue.Contains(30));
}

TEST(Size, Empty) {
    PriorityQueue<int> queue = PriorityQueue<int>();
    EXPECT_EQ(queue.Size(), 0);
}

TEST(Size, MultipleElements) {
    PriorityQueue<int> queue = PriorityQueue<int>();
    queue.Push(4);
    queue.Push(5);
    queue.Push(3);
    queue.Push(1);
    EXPECT_EQ(queue.Size(), 4);
}

TEST(Size, DuplicateElementsAreStillThere) {
    PriorityQueue<int> queue = PriorityQueue<int>();
    queue.Push(10);
    queue.Push(10);
    EXPECT_EQ(queue.Size(), 2);
}

TEST(Pop, OneElement) {
    PriorityQueue<int> queue = PriorityQueue<int>();
    queue.Push(11);
    EXPECT_EQ(queue.Pop(), 11);
    EXPECT_EQ(queue.Size(), 0);
}

TEST(Pop, UnorderedElements) {
    PriorityQueue<int> queue = PriorityQueue<int>();
    queue.Push(2);
    queue.Push(3);
    queue.Push(1);
    queue.Push(4);
    EXPECT_EQ(queue.Pop(), 1);
    EXPECT_EQ(queue.Pop(), 2);
    EXPECT_EQ(queue.Pop(), 3);
    EXPECT_EQ(queue.Pop(), 4);
}

TEST(PushVector, InitializeMultipleValues) {
    PriorityQueue<int> queue = PriorityQueue<int>();
    std::vector<int> edges = {4, 1, 7};
    queue.Push(edges);
    EXPECT_EQ(queue.Size(), 3);
    EXPECT_EQ(queue.Pop(), 1);
    EXPECT_EQ(queue.Pop(), 4);
    EXPECT_EQ(queue.Pop(), 7);
}

TEST(PushVector, SingleToSingle) {
    PriorityQueue<int> queue = PriorityQueue<int>();
    queue.Push(1);
    std::vector<int> value = {2};
    queue.Push(value);
    EXPECT_EQ(queue.Size(), 2);
}

TEST(PushVector, MultiToMulti) {
    PriorityQueue<int> queue = PriorityQueue<int>();
    std::vector<int> init = {5, 2, 8};
    queue.Push(init);
    std::vector<int> more = {1, 7, 4};
    queue.Push(more);
    EXPECT_EQ(queue.Pop(), 1);
    EXPECT_EQ(queue.Pop(), 2);
    EXPECT_EQ(queue.Pop(), 4);
    EXPECT_EQ(queue.Pop(), 5);
    EXPECT_EQ(queue.Pop(), 7);
    EXPECT_EQ(queue.Pop(), 8);
}

TEST(PushVector, EmptyToEmpty) {
    PriorityQueue<int> queue = PriorityQueue<int>();
    std::vector<int> empty;
    queue.Push(empty);
    EXPECT_EQ(queue.Size(), 0);
}

TEST(Edge, SingleEdge) {
    PriorityQueue<Edge> queue = PriorityQueue<Edge>();
    Edge edge = Edge(0, 1);
    queue.Push(edge,10);
    EXPECT_EQ(queue.Pop(), edge);
}

TEST(Performance, ProjectCase) {
    PriorityQueue<int> queue = PriorityQueue<int>();
    for (int i = 0; i < 1225; i++) {
        queue.Push(std::rand());
    }
    EXPECT_EQ(queue.Size(), 1225);
    while (!queue.IsEmpty()) {
        queue.Pop();
    }
    EXPECT_TRUE(queue.IsEmpty());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
