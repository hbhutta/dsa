/**
 * Illustrating the use of pointers in writing a 
 * correct swap function, which is commonly used
 * in sorting algorithms
*/

#include <iostream>

void wrongSwap(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

void correctSwap(int* x, int* y) {
    int temp = *x; // * is used to dereference the pointer
    *x = *y; // *x and *y are the specific objects pointed to
    *y = temp; // y is a pointer but *y is an int (the object pointed to)
}

int main() {
    int a = 5;
    int b = 7;

    std::cout << a << ", " << b << std::endl; // Should be 5, 7

    wrongSwap(a, b);

    std::cout << a << ", " << b << std::endl; // Should still be 5, 7

    // Passing references to a and b (i.e., their memory addresses)
    correctSwap(&a, &b); 

    std::cout << a << ", " << b << std::endl; // Should still be 7, 5

    return 0;
}