
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <queue>

#include "IGraph.h"
#include "SetGraph.h"
#include "utils.hpp"

using std::cout;
using std::cin;
using std::endl;

SetGraph::SetGraph (int count) {
    sets.resize(count);
}

SetGraph::SetGraph (const IGraph& graph) {
    for(int i = 0; i < graph.VerticesCount(); ++i) {
        auto tmp = graph.GetNextVertices(i);
        std::unordered_set<int> vertex;
        std::for_each(tmp.begin(), tmp.end(), [&](int v) {vertex.emplace(v);});
        sets.push_back(vertex);
        vertex.clear();
    }
}

void SetGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < sets.size());
    assert(to >= 0 && to < sets.size());

    sets[from].emplace(to);
}

int SetGraph::VerticesCount() const {
    return sets.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    assert(vertex >= 0 && vertex < sets.size());

    std::vector<int> nextVerticies;
    auto tmp = sets[vertex];
    std::for_each(tmp.begin(), tmp.end(), [&](int v) {nextVerticies.push_back(v);});

    printGivenVertices(nextVerticies);

    return nextVerticies;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    assert(vertex >= 0 && vertex < sets.size());

    std::vector<int> prevVerticies;
    for (int i = 0; i < VerticesCount(); ++i) {
        if (sets[i].find(vertex) != sets[i].end()) {
            prevVerticies.push_back(i);
        }
    }

    return prevVerticies;
}
