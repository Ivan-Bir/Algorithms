
#include <iostream>
#include <vector>
#include <cassert>
#include <queue>

template<typename T>
void printMatrix(std::vector<std::vector<T>> matrix) {
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix.size(); ++j) {
            std::cout << "[" << matrix[i][j] << "] ";
        }
        std::cout << std::endl;
    }
}

template<typename T>
void printGivenVertices(std::vector<T> next_vertices) {
    std::cout << "Given Vertices:" << std::endl;
    std::for_each(next_vertices.begin(), next_vertices.end(), [](int v) {std::cout << v << ", ";});
    std::cout << std::endl;
}

template<typename T>
bool compare_vectors(std::vector<T> v1, std::vector<T> v2) {
    if (v1.size() != v2.size()) {
        return false;
    }

    bool result = true;
    for (int i = 0; i < v1.size() && result; ++i) {
        result = result && (v1[i] == v2[i]);
    }
    return result;
}