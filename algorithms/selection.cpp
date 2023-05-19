#include <iostream>
#include <cmath>
#include <vector>

/**
 * 1. Find the current min of array
 * 2. Put it at the front (at index pos. 0)
 * 3. Repeat until sorted
 * 
 * @param vector<int> The array to be sorted
 * @return The sorted array
*/
std::vector<int> selectionSortSmallest(std::vector<int> arr) {
    int currentMin = INFINITY;
    int store = 0;

    // 1. Find current min
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size(); j++) {
            if (arr[j] <= currentMin) {
                currentMin = arr[j]; // Realize that arr[i] is the current min
                store = arr[0]; // Store the front so it's not lost

                // Swap procedure
                arr[0] = arr[j]; // Put the current min all the way at the front (LHS of arr.)
                arr[j] = store; // Swap (constant time)
            }
        }
    } 
    return arr;
}

/**
 * Find largest element and put it in fron of the currunt unsorted portion of the array
*/
std::vector<int> selectionSortLargest(std::vector<int> arr) {

    std::vector<int> copy = arr;
    int currMax = 0;
    int store = 0;

    for (int i = 0; i < copy.size(); i++) {
        if (copy[i] >= currMax) {
            store = copy[copy.size() - 1];
            copy[copy.size() - 1] = currMax;
            copy[i] = copy[copy.size() - 1];

            currMax = copy[i];
        }
    }
}

/**
 * @param vector The array
 * @param int The left-hand side index of the processed sub-array
 * @return The index of the minimum in arr, from i to the end of the array
*/
int indexOfMin(std::vector<int> arr, int a) {
    int m = a;
    for (int i = a+1; i < arr.size(); i++) {
        if (arr[i] < m) {
            m = i;
        }
    }
    return m;
}

/**
 * Selection sort:
 * Select the smallest item (that has not been processed so far) and put it into place
*/
std::vector<int> selectionSortNew(std::vector<int> arr) {
    int store = 0;

    for (int i = 0; i < arr.size(); i++) {
        int min = indexOfMin(arr, i);
        // Swap arr[i] and min
        store = arr[i];
        arr[i] = min;
        min = store;
    }
}


/**
 * While fixed on the i-th element of the array,
 * iterate through the entire array. While iterating,
 * if the j-th element in the array is less than the i-th
 * element of the array, for j > i, then swap the elements at 
 * the indices i and j.
 * 
 * Worst case: O(n^2)
 * Best case: O(n^2)
 * Average case: O(n^2)
*/
std::vector<int> insertionSort(std::vector<int> arr) { // Getting a segmentation fault
    int store = 0;
    for (int i = 0; i < arr.size(); i++) {
        int key = arr[i]; // curr
        int j = i - 1;
        // Moving all the elements one space to the right ...?
        while (j >= 0 && arr[j] > key) {
            
        }
    }
}



std::vector<int> bubbleSort(std::vector<int> arr) {
    int store = 0;
    int count = 0;
    for (int i = 0; i < arr.size(); i++) {
        /**
         * j < arr.size() - 2 to make sure the  sliding range does 
         * not go out of the window
        */
        for (int j = 0; j < arr.size() - 1; j++) { 
            if (arr[j] > arr[j+1]) {
                // arr = swap(arr, j, j+1);
                store = arr[j];
                arr[j] = arr[j + 1];
                arr[j+1] = store;
                count = 0; // reset count if not already zero
            }
            else {
                count++;
            }
            if (count == arr.size() - 2) {
                return arr;
            }
        }
    }
    return arr;
}

// std::vector<int>& swap(std::vector<int>& arr, int& a, int b) {
//     int store = arr[a];
//     arr[a] = arr[b];
//     arr[b] = store;
//     return arr;
// }

void printArray(std::vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n" << std::endl;
}

int main() {
    std::vector<int> arr = {23, 41, 33, 81, 7, 19, 11, 45};
    printArray(arr);
    printArray(selectionSortSmallest(arr));
    // printArray(insertionSort(arr));
    printArray(bubbleSort(arr));
    return 0;
}