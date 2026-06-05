#include <iostream>
#include <vector>
#include <fstream>

std::vector<std::vector<int>> add(std::vector<std::vector<int>> A, std::vector<std::vector<int>> B);
std::vector<std::vector<int>> matmul(std::vector<std::vector<int>> A, std::vector<std::vector<int>> B);

int main() {
    std::ifstream inFile;
    inFile.open("matrices.txt");

    if (inFile.fail()) {
        std::cout << "Error opening file." << std::endl;
        return 1;
    }

    size_t m,n;
    inFile >> m >> n;

    std::vector<std::vector<int>> A;

    for (size_t i = 0; i < m; i++) {
        std::vector<int> row;
        for (size_t j = 0; j < n; j++) {
            int a;
            inFile >> a;
            row.push_back(a);
        }
        A.push_back(row);
    }

    size_t q,p;
    inFile >> q >> p;
    std::vector<std::vector<int>> B;

    for (size_t i = 0; i < q; i++) {
        std::vector<int> row;
        for (size_t j = 0; j < p; j++) {
            int b;
            inFile >> b;
            row.push_back(b);
        }
        B.push_back(row);
    }

    inFile.close();

    std::vector<std::vector<int>> sum = add(A, B);
    std::vector<std::vector<int>> prod = matmul(A, B);

    std::ofstream outFile("results.text");

    outFile << "Sum: " << std::endl;
    for (auto& row : sum) {
        for (auto& val : row) {
            outFile << val << " ";
        }
        outFile << std::endl;
    }

    outFile << "Prod: " << std::endl;
    for (auto& row : prod) {
        for (auto& val : row) {
            outFile << val << " ";
        }
        outFile << std::endl;
    }

    outFile.close();

    return 0;
}

std::vector<std::vector<int>> add(std::vector<std::vector<int>> A, std::vector<std::vector<int>> B) {
    size_t m = A.size();
    size_t n = A[0].size();
    size_t q = B.size();
    size_t p = B[0].size();

    if (m != q || n != p) {
        std::cout << "You can only add two m x n matrices." << std::endl;
        return {{}};
    }
    else {
        std::vector<std::vector<int>> C(n, std::vector<int>(n,0));

        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                C[i][j] = A[i][j] + B[i][j];
            }
        }
        return C;
    }
}

std::vector<std::vector<int>> matmul(std::vector<std::vector<int>> A, std::vector<std::vector<int>> B) {
    size_t n = A.size();
    size_t m = A[0].size();
    size_t q = B.size();
    size_t p = B[0].size();

    if (m != q) {
        std::cout << "You can only multiply an m x n and n x p matrix. " << std::endl;
        return {{}};
    }
    else {
        std::vector<std::vector<int>> C(m, std::vector<int>(p,0));

        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < p; j++) {
                C[i][j] = 0;
                for (size_t k = 0; k < m; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return C;
    }
}
