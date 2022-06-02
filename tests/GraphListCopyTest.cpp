#include <gtest/gtest.h>

#include <iostream>
#include <functional>
#include <vector>
#include <cassert>
#include <queue>
#include <algorithm>

#include "IGraph.h"
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "ArcGraph.h"
#include "SetGraph.h"

#include "utils.hpp"

static std::vector<std::vector<int>> next_cases = {
    {2, 5},
    {3},
    {1, 5},
    {2, 4},
    {0, 5},
    {0},
};

static std::vector<std::vector<int>> prev_cases = {
    {4, 5},
    {2},
    {0, 3},
    {1},
    {3},
    {0, 2, 4},
};


TEST(ListFromMatrix, Copy) {
    std::unique_ptr<IGraph> Mgraph = std::make_unique<MatrixGraph>(6);
    Mgraph->AddEdge(0,2);
    Mgraph->AddEdge(0,5);
    Mgraph->AddEdge(1,3);
    Mgraph->AddEdge(2,1);
    Mgraph->AddEdge(2,5);
    Mgraph->AddEdge(3,2);
    Mgraph->AddEdge(3,4);
    Mgraph->AddEdge(4,0);
    Mgraph->AddEdge(4,5);
    Mgraph->AddEdge(5,0);

    std::unique_ptr<IGraph> Lgraph = std::make_unique<ListGraph>(*Mgraph);

    for (int i = 0; i < Lgraph->VerticesCount(); ++i) {
        EXPECT_TRUE(compare_vectors(next_cases[i], Lgraph->GetNextVertices(i)));
        EXPECT_TRUE(compare_vectors(prev_cases[i], Lgraph->GetPrevVertices(i)));
    }
}

TEST(ListFromArc, Copy) {
    std::unique_ptr<IGraph> Agraph = std::make_unique<ArcGraph>(6);
    Agraph->AddEdge(0,2);
    Agraph->AddEdge(0,5);
    Agraph->AddEdge(1,3);
    Agraph->AddEdge(2,1);
    Agraph->AddEdge(2,5);
    Agraph->AddEdge(3,2);
    Agraph->AddEdge(3,4);
    Agraph->AddEdge(4,0);
    Agraph->AddEdge(4,5);
    Agraph->AddEdge(5,0);

    std::unique_ptr<IGraph> Lgraph = std::make_unique<ListGraph>(*Agraph);

    for (int i = 0; i < Lgraph->VerticesCount(); ++i) {
        EXPECT_TRUE(compare_vectors(next_cases[i], Lgraph->GetNextVertices(i)));
        EXPECT_TRUE(compare_vectors(prev_cases[i], Lgraph->GetPrevVertices(i)));
    }
}

TEST(ListFromSet, Copy) {
    std::unique_ptr<IGraph> Sgraph = std::make_unique<SetGraph>(6);
    Sgraph->AddEdge(0,2);
    Sgraph->AddEdge(0,5);
    Sgraph->AddEdge(1,3);
    Sgraph->AddEdge(2,1);
    Sgraph->AddEdge(2,5);
    Sgraph->AddEdge(3,2);
    Sgraph->AddEdge(3,4);
    Sgraph->AddEdge(4,0);
    Sgraph->AddEdge(4,5);
    Sgraph->AddEdge(5,0);

    std::unique_ptr<IGraph> Lgraph = std::make_unique<ListGraph>(*Sgraph);

    for (int i = 0; i < Lgraph->VerticesCount(); ++i) {
        auto tmp = Lgraph->GetNextVertices(i);
        std::sort(tmp.begin(), tmp.end());

        EXPECT_TRUE(compare_vectors(next_cases[i], tmp));

        tmp = Lgraph->GetPrevVertices(i);
        std::sort(tmp.begin(), tmp.end());

        EXPECT_TRUE(compare_vectors(prev_cases[i], tmp));
    }
}

TEST(ListFromList, Copy) {
    std::unique_ptr<IGraph> Lgraph = std::make_unique<ListGraph>(6);
    Lgraph->AddEdge(0,2);
    Lgraph->AddEdge(0,5);
    Lgraph->AddEdge(1,3);
    Lgraph->AddEdge(2,1);
    Lgraph->AddEdge(2,5);
    Lgraph->AddEdge(3,2);
    Lgraph->AddEdge(3,4);
    Lgraph->AddEdge(4,0);
    Lgraph->AddEdge(4,5);
    Lgraph->AddEdge(5,0);

    std::unique_ptr<IGraph> newLgraph = std::make_unique<ListGraph>(*Lgraph);

    for (int i = 0; i < newLgraph->VerticesCount(); ++i) {
        EXPECT_TRUE(compare_vectors(next_cases[i], newLgraph->GetNextVertices(i)));
        EXPECT_TRUE(compare_vectors(prev_cases[i], newLgraph->GetPrevVertices(i)));
    }
}
