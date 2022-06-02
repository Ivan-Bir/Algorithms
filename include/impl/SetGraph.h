#pragma once

#include "IGraph.h"

#include <vector>
#include <unordered_set>

struct SetGraph : IGraph {
    SetGraph(int count);
    explicit SetGraph(const IGraph& graph);

    virtual void AddEdge(int from, int to) override;
    virtual int VerticesCount() const override;

    virtual std::vector<int> GetNextVertices(int vertex) const override;
    virtual std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::unordered_set<int>> sets;
};
