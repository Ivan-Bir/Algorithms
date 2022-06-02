
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <queue>

#include "IGraph.h"
#include "MatrixGraph.h"
#include "utils.hpp"

using std::cout;
using std::cin;
using std::endl;

#define EXIST_WAY 1
#define NO_WAY 0

MatrixGraph::MatrixGraph (int count) {
    matrix.resize(count);
    for (int i = 0; i < count; ++i) {
        matrix[i].resize(count);
    }

    // printMatrix(matrix);
}

MatrixGraph::MatrixGraph (const IGraph& graph) {
    // std::cout << "COPY CONSTRUCTOR MGRAPH" << std::endl;

    matrix.resize(graph.VerticesCount());
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        matrix[i].resize(graph.VerticesCount());
    }

    for(int i = 0; i < graph.VerticesCount(); ++i) {
        auto tmp = graph.GetNextVertices(i);
        std::for_each(tmp.begin(), tmp.end(), [=](int v) {matrix[i][v] = EXIST_WAY;});
    }

    // printMatrix(matrix);
}

void MatrixGraph::AddEdge(int from, int to) {
    assert(from >= 0 && matrix.size());
    assert(to >= 0 && to < matrix.size());
    matrix[from][to] = EXIST_WAY;

    // std::cout << "ADDED EDGE" << std::endl;
    // printMatrix(matrix);
}

int MatrixGraph::VerticesCount() const {
    return matrix.size();
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    assert(vertex >= 0 && vertex < matrix.size());
    std::vector<int> nextVerticies;
    for (size_t i = 0; i < matrix.size(); ++i) {
        if (matrix[vertex][i] == EXIST_WAY) {
            nextVerticies.push_back(i);
        }
    }
    return nextVerticies;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    assert(vertex >= 0 && vertex < matrix.size());
    std::vector<int> prevVerticies;
    for (size_t i = 0; i < matrix.size(); ++i) {
        if (matrix[i][vertex] == EXIST_WAY) {
            prevVerticies.push_back(i);
        }
    }

    // printGivenVertices(prevVerticies);
    return prevVerticies;
}


// //////////////////////////////////////////////////////////////////////////////
// void BFS(const IGraph& graph, int vertex, void (*visit)(int)) {
//     std::vector<char> visited(graph.VerticesCount(), 0);

//     std::queue<int> bfsQueue;
//     bfsQueue.push(vertex);
//     visited[vertex] = 1;
//     while(bfsQueue.size() > 0) {
//         int current = bfsQueue.front();
//         bfsQueue.pop();
//         visit(current);
//         std::vector<int> matrix = graph.GetNextVertices(current);
//         for (size_t i = 0; i < matrix.size(); ++i) {
//             if (!visited[matrix[i]]) {
//                 bfsQueue.push(matrix[i]);
//                 visited[matrix[i]] = 1;
//             }
//         }
//     }
// }