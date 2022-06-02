#pragma once

#include "IGraph.h"

#include <vector>

struct MatrixGraph : IGraph {
    MatrixGraph(int count);
    explicit MatrixGraph(const IGraph& graph);

    virtual void AddEdge(int from, int to) override;
    virtual int VerticesCount() const override;

    virtual std::vector<int> GetNextVertices(int vertex) const override;
    virtual std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::vector<int>> matrix;
};
