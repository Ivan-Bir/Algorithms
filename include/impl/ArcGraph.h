#pragma once

#include "IGraph.h"

#include <vector>

struct ArcGraph : IGraph {
    ArcGraph(int count);
    explicit ArcGraph(const IGraph& graph);

    virtual void AddEdge(int from, int to) override;
    virtual int VerticesCount() const override;

    virtual std::vector<int> GetNextVertices(int vertex) const override;
    virtual std::vector<int> GetPrevVertices(int vertex) const override;

private:
    struct Edge {
        int from;
        int to;

        Edge(int from, int to) : from(from), to(to) {}
    };

    int count_vertices;
    std::vector<Edge> edges;
};