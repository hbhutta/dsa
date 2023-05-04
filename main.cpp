// #include <my_sort.hpp>
#include <iostream>

class MySort {
    public:
        MySort() {} 

        int size(int arr[]) {
            return sizeof(arr) / sizeof(*arr);
        }

        void printArray(int arr[], int size) {
            for (int i = 0; i < size; i++) {
                std::cout << arr[i] << std::endl;
            }
        }

        /**
         * reachSort: O(size^2)
         * e.g. [3,2,1], n = 3;
         * [3,2,1] -> [3,2,1] -> [2,3,1] -> [1,3,2], ++
         * -> [1,3,2] -> [1,2,3]
        */
        void reachSort(int arr[], int size) {
            printArray(arr, size); // initial
            int store, first, reached;
            for (int i = 0; i < size; i++) {
                int first = arr[i];
                for (int j = 0; j < size; j++) {
                    reached = arr[j];
                    if (first > reached) {
                        std::cout << "Test" << std::endl;
                        store = first;
                        first = reached;
                        reached = store;
                    }
                }
            } 
            printArray(arr, size); // after reachSort
        }   
};

int main() {
    int A[3] = {3, -2, 1};
    int B[17] = {3, 2, 1};
    int C[1] = {3, 2, 1};
    int D[0] = {};
    int E[4] = {1, -1, 1};
    MySort mySort;
    mySort.reachSort(A, mySort.size(A));
}


