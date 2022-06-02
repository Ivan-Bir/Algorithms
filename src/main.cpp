#include <iostream>
#include <functional>
#include <vector>
#include <cassert>
#include <queue>
#include <memory>

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

int main() {
    // emplace your logic for graph here

    std::cout << "RUN MAIN" << std::endl;
    return EXIT_SUCCESS;
}
