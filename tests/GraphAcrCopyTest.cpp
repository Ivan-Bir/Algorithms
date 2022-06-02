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


TEST(ArcFromMatrix, Copy) {
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

    std::unique_ptr<IGraph> Agraph = std::make_unique<ArcGraph>(*Mgraph);

    for (int i = 0; i < Agraph->VerticesCount(); ++i) {
        EXPECT_TRUE(compare_vectors(next_cases[i], Agraph->GetNextVertices(i)));
        EXPECT_TRUE(compare_vectors(prev_cases[i], Agraph->GetPrevVertices(i)));
    }
}

TEST(ArcFromList, Copy) {
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

    std::unique_ptr<IGraph> Agraph = std::make_unique<ArcGraph>(*Lgraph);

    for (int i = 0; i < Agraph->VerticesCount(); ++i) {
        EXPECT_TRUE(compare_vectors(next_cases[i], Agraph->GetNextVertices(i)));
        EXPECT_TRUE(compare_vectors(prev_cases[i], Agraph->GetPrevVertices(i)));
    }
}
