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


TEST(MatrixFromList, Copy) {
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

    std::unique_ptr<IGraph> Mgraph = std::make_unique<MatrixGraph>(*Lgraph);

    for (int i = 0; i < Mgraph->VerticesCount(); ++i) {
        EXPECT_TRUE(compare_vectors(next_cases[i], Mgraph->GetNextVertices(i)));
        EXPECT_TRUE(compare_vectors(prev_cases[i], Mgraph->GetPrevVertices(i)));
    }
}


TEST(MatrixfromArc, Copy) {
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

    std::unique_ptr<IGraph> Mgraph = std::make_unique<MatrixGraph>(*Agraph);

    for (int i = 0; i < Mgraph->VerticesCount(); ++i) {
        EXPECT_TRUE(compare_vectors(next_cases[i], Mgraph->GetNextVertices(i)));
        EXPECT_TRUE(compare_vectors(prev_cases[i], Mgraph->GetPrevVertices(i)));
    }
}