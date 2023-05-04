#include <mysort.hpp>

int main() {
    int A[3] = {3, -2, 1};
    int B[3] = {3, 2, 1};
    int C[1] = {3};
    int D[0] = {};
    int E[4] = {1, -1, 1};
    MySort mySort;
    mySort.reachSort(A, mySort.size(A));
}


