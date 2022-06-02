#include <iostream>
#include <functional>
#include <vector>
#include <cassert>
#include <queue>
#include <memory>

#include "IGraph.h"
#include "ListGraph.h"
#include "MatrixGraph.h"

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

    std::unique_ptr<IGraph> graph = std::make_unique<ListGraph>(6);
    graph->AddEdge(1,3);
    graph->AddEdge(2,1);
    graph->AddEdge(2,3);
    graph->AddEdge(2,4);
    graph->AddEdge(3,4);
    graph->AddEdge(4,5);
    graph->AddEdge(5,3);
    graph->AddEdge(5,4);

    std::unique_ptr<IGraph> Mgraph = std::make_unique<MatrixGraph>(*graph);
    Mgraph->AddEdge(0,1);
    Mgraph->AddEdge(0,5);
    Mgraph->AddEdge(5,0);
    Mgraph->AddEdge(3,1);

    Mgraph->GetNextVertices(1);
    Mgraph->GetPrevVertices(1);


    std::cout << "RUN MAIN" << std::endl;
    return EXIT_SUCCESS;
}
