
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <queue>

#include "IGraph.h"
#include "ArcGraph.h"
#include "utils.hpp"

using std::cout;
using std::cin;
using std::endl;


ArcGraph::ArcGraph (int count) : count_vertices(count) {}

ArcGraph::ArcGraph (const IGraph& graph) : count_vertices(graph.VerticesCount()) {
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        auto tmp = graph.GetNextVertices(i);
        std::for_each(tmp.begin(), tmp.end(), [=](int v) {edges.push_back(Edge(i, v));});
    }
}

void ArcGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < count_vertices);
    assert(to >= 0 && to < count_vertices);

    edges.push_back(Edge(from, to));
}

int ArcGraph::VerticesCount() const {
    return count_vertices;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    assert(vertex >= 0 && vertex < VerticesCount());

    std::vector<int> nextVerticies;
    std::for_each(edges.begin(), edges.end(), [&](Edge v) {
        if (v.from == vertex) {
            nextVerticies.push_back(v.to);
        }
    });
    return nextVerticies;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    assert(vertex >= 0 && vertex < VerticesCount());

    std::vector<int> prevVerticies;
    std::for_each(edges.begin(), edges.end(), [&](Edge v) {
        if (v.to == vertex) {
            prevVerticies.push_back(v.from);
        }
    });

    return prevVerticies;
}
