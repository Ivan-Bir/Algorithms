
#include <iostream>
#include <vector>
#include <cassert>
#include <queue>

#include "IGraph.h"
#include "ListGraph.h"

using std::cout;
using std::cin;
using std::endl;


ListGraph::ListGraph (int count) {
    adjList.resize(count);
}

ListGraph::ListGraph (const IGraph& graph) {
    adjList.resize(graph.VerticesCount());
    for(int i = 0; i < graph.VerticesCount(); ++i) {
        adjList[i] = graph.GetNextVertices(i);
    }
}

void ListGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < adjList.size());
    assert(to >= 0 && to < adjList.size());
    adjList[from].push_back(to);
}

int ListGraph::VerticesCount() const {
    return adjList.size();
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
    assert(vertex >= 0 && vertex < adjList.size());
    return adjList[vertex];
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
    assert(vertex >= 0 && vertex < adjList.size());
    std::vector<int> prevVerticies;
    for (size_t from = 0; from < adjList.size(); ++from) {
        for (size_t i = 0; i < adjList[from].size(); ++i) {
            if (adjList[from][i] == vertex) {
                prevVerticies.push_back(from);
            }
        }
    }
    return prevVerticies;

}


//////////////////////////////////////////////////////////////////////////////
void BFS(const IGraph& graph, int vertex, void (*visit)(int)) {
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