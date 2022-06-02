#include <gtest/gtest.h>

#include <iostream>
#include <functional>
#include <vector>
#include <cassert>
#include <queue>
#include <algorithm>

#include "IGraph.h"
#include "ListGraph.h"
#include "MatrixGraph.h"

#include "utils.hpp"

// void BFS(const IGraph& graph, int vertex, const std::function<void(int)> visit) {
//     std::vector<char> visited(graph.VerticesCount(), 0);

//     std::queue<int> bfsQueue;
//     bfsQueue.push(vertex);
//     visited[vertex] = 1;
//     while(bfsQueue.size() > 0) {
//         int current = bfsQueue.front();
//         bfsQueue.pop();
//         visit(current);
//         std::vector<int> adjList = graph.GetNextVertices(current);
//         for (size_t i = 0; i < adjList.size(); ++i) {
//             if (!visited[adjList[i]]) {
//                 bfsQueue.push(adjList[i]);
//                 visited[adjList[i]] = 1;
//             }
//         }
//     }
// }

static std::vector<std::vector<int>> next_cases = {
    {2, 5},
    {3},
    {1, 5},
    {2, 4},
    {0, 5},
    {0},
};

static std::vector<std::vector<int>> prev_cases = {
    {4, 5},
    {2},
    {0, 3},
    {1},
    {3},
    {0, 2, 4},
};



TEST(buildListGraph, Build) {
    std::unique_ptr<IGraph> graph = std::make_unique<ListGraph>(6);
    graph->AddEdge(0,2);
    graph->AddEdge(0,5);
    graph->AddEdge(1,3);
    graph->AddEdge(2,1);
    graph->AddEdge(2,5);
    graph->AddEdge(3,2);
    graph->AddEdge(3,4);
    graph->AddEdge(4,0);
    graph->AddEdge(4,5);
    graph->AddEdge(5,0);

    for (int i = 0; i < graph->VerticesCount(); ++i) {
        EXPECT_TRUE(compare_vectors(next_cases[i], graph->GetNextVertices(i)));
        EXPECT_TRUE(compare_vectors(prev_cases[i], graph->GetPrevVertices(i)));
    }
};


TEST(buildMatrixGraph, Build) {
    std::unique_ptr<IGraph> graph = std::make_unique<MatrixGraph>(6);
    graph->AddEdge(0,2);
    graph->AddEdge(0,5);
    graph->AddEdge(1,3);
    graph->AddEdge(2,1);
    graph->AddEdge(2,5);
    graph->AddEdge(3,2);
    graph->AddEdge(3,4);
    graph->AddEdge(4,0);
    graph->AddEdge(4,5);
    graph->AddEdge(5,0);

    for (int i = 0; i < graph->VerticesCount(); ++i) {
        EXPECT_TRUE(compare_vectors(next_cases[i], graph->GetNextVertices(i)));
        EXPECT_TRUE(compare_vectors(prev_cases[i], graph->GetPrevVertices(i)));
    }
};




