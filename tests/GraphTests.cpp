#include <gtest/gtest.h>

#include <iostream>
#include <functional>
#include <vector>
#include <cassert>
#include <queue>
#include <algorithm>

#include "IGraph.h"
#include "ListGraph.h"

void BFS(const IGraph& graph, int vertex, const std::function<void(int)> visit) {
    std::vector<char> visited(graph.VerticesCount(), 0);

    std::queue<int> bfsQueue;
    bfsQueue.push(vertex);
    visited[vertex] = 1;
    while(bfsQueue.size() > 0) {
        int current = bfsQueue.front();
        bfsQueue.pop();
        visit(current);
        std::vector<int> adjList = graph.GetNextVertices(current);
        for (size_t i = 0; i < adjList.size(); ++i) {
            if (!visited[adjList[i]]) {
                bfsQueue.push(adjList[i]);
                visited[adjList[i]] = 1;
            }
        }
    }
}

template<typename T>
bool compare_vectors(std::vector<T> v1, std::vector<T> v2) {
    if (v1.size() != v2.size()) {
        return false;
    }

    bool result = true;
    for (int i = 0; i < v1.size() && result; ++i) {
        result = result && (v1[i] == v2[i]);
    }
    return result;
}

TEST(buildListGraph, Build) {
    std::unique_ptr<IGraph> graph = std::make_unique<ListGraph>(6);
    graph->AddEdge(1,3);
    graph->AddEdge(2,1);
    graph->AddEdge(2,3);
    graph->AddEdge(2,4);
    graph->AddEdge(3,4);
    graph->AddEdge(4,5);
    graph->AddEdge(5,3);
    graph->AddEdge(5,4);

    std::vector<int> expected_data = {2, 1, 3, 4, 5};

    std::vector<int> visited_vertices;
    BFS(*graph, 2, [&visited_vertices](int v){visited_vertices.push_back(v);});

    EXPECT_TRUE(compare_vectors(visited_vertices, expected_data));

}

