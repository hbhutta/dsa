# Analyzing sorting algorithms using loop invariants


## Selection sort

### Basic idea
### Running times

- Best case:
- Worst case:
- Average case:
```c++
vector<int> selectionSort(vector<int> arr) {

}
```

## Insertion sort
### Basic idea
Create a new array and **insert** the elements from the given array into this new array in a "sorted" way.


### Running times
- Best case:
- Worst case:
- Average case:
```c++
vector<int> insert(vector<int> arr, int p) {
    // Assumes arr[0 ... p - 1] are in sorted order
    int temp = arr[p];
    int j = p;
    // j > 0 makes sure the end of the array is not reached
    // arr[j-1] > temp makes sure temp is inserted in the right place 
    while (j > 0 && arr[j-1] > temp) {
        arr[j-1] = arr[j]; // Shift the (j-1)-th element to the right
        j--; // Move on to check the next element
    }
    arr[j] = temp;
}
```

## Bubble sort
### Basic idea:
From left to right, compare immediate neighbours.
If the left neighbour is greater than the right neighbour (i.e., the neighbours are in descending order, when they should be *ascending*), then swap the neighbours. Eventually the end of the array is reached; this was the first pass. Now keep doing these "passes" (using nested `for` loops), until the entire array is sorted.
### Running times
- Best case: $\Omega(n)$ (i.e., given array is in strictly-increasing order)
- Worst case: $O(n^2)$ (i.e., given array is in strictly-decreasing order)
- Average case: $\Theta(n^2)$ 
```c++
vector<int> bubbleSort(vector<int> arr) {

}
```

# May 17, 2023 (Wednesday): Correctness and Iterative Sorting

```c++
int indexOfMin(vector<int>& arr, int a) {
    int m = a;
    for (int i = a + 1; i < arr.size(); i++) {
        if (arr[i] < arr[m]) {
            m = i;
        }
    }
    return m;
}
```
For example, given the following arguments
```
arr[9, 11, 13, 16, 20, 14, 37, 21]
```
- What does it do?
    - Returns the index of the smallest element past position `a`



# Pointers
```cpp
int x = 5; // Declaration and inititalization
int* p = &x;

std::cout << x << std::endl; // Should be 5

*(p) = 2; // I derefence the pointer, and change the value of x to 2.

std::cout << x << std::endl; // Should be 2
```

## Linked lists 
In C++, a linked list class can be written from scratch using pointers

```cpp
// Every node stores its own value, and the memory address of the node it points to
class Node {
    int value; // Value of this node
    Node* next; // A pointer to the next node in the "linked" list
};
```

Now by looking at this definition, we can get an idea of the time complexities of 
basic container operations (e.g., insertion/deletetion, access)

Let's say I have the linked list : 
```[1 -> 2 -> 3 -> 5] ```

And I want to insert `4` between `3` and `5`. Suppose these numbers represent the "nodes" in the linked list. Right now `3` points to `5`. To insert `4` between them, I just have to make make `3` point to `4` instead of `5`, and also make `4` point to `5` to make sure the linked list is "connected" and there are no dangling pointers


A linked list implementation using `struct Node` can have either one or both the head and the tail nodes.

The runtime of insertion depends on where we inserting (at front, end or middle) and on 
whether or not we have the head and/or the tail pointer.

So if I want to insert at the front, and I have a head pointer, then it's constant time $\mathcal{O}(1)$, but if I *don't* have a head pointer, then insertion at the front is $\mathcal{O}(n)$

Why???

What does it mean to have a head and tail nodes? Aren't these just the first and last nodes 
in the linked list?

## Call-by-reference (when passing arguments into functions)
Instead of passing the value of the variable into a function (call-by-value), 
call-by-reference means passing the memory address of the variable into the function

```cpp
```

## The problems with doing call-by-value in the swap function

```cpp
void swap(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

int a = 5;
int b = 7;
swap(a,b);
```
So this above code does not actually swap `a` and `b`, as we would desire.

What actually happens is that the value of `a` is assigned to `x` and the value of `b` is assigned to `y`. So the swap procedure only happens to `x` and `y` because once they store the values of `a` and `b` respectively, we don't really use `a` and `b` after.

So when we use `swap` function here, we need to somehow preserve the fact that *specifically* `a` and `b` are being swapped, and not some new variables `x` and `y` which are irrelevant to what we actually want to get done. So we need to pass the memory addresses of `a` and `b` into `swap` as follows:

```cpp
void swap(int& a, int& b) {

}
```

The general idea is that `&` is the reference operator that is used to get the memory address of a variable, while `*` is the *dereference* operator that gets the actual value stored at the memory address (i.e. at a reference). This is why pointers need to be dereferenced; because they store the memory address of the variable they point to:
- `&var` means "address of" `var`
- `*var` means "object stored at memory address" `var`


## Stack vs heap 

Using the `new` keyword requests space in the heap; so the variable gets memory 
allocated for it in the heap, not in the stack.

These two lines are different:
```cpp
int* b; // Allocates (static) memory on the stack
int* b = new int; // Allocates (dynamic) memory on the heap
```

Memory allocated on the heap must be deleted using the `delete` keyword once the variables have been used. There is also `delete[]` (with the square brackets) which releases memory allocated to array variables

Dangling pointers cause a segfault


## Segmentation faults

NULL vs nullptr 
- nullptr is more safe to use and is more modern
- nullptr has both a value of NULL and is a pointer type
- nullptr can be used for type comparison 


Memory leak is when memory on the heap is just hanging around because access to it has been lost

Things are only added to the heap when the new keyword is used

For example `vector` is dynamic, so they have heap allocation

When done with pointers, just set them to null

This is why we use programs like valgrind, and gdb



## Class vs struct

structs only contain attributes and variables and are typically 
used when we have only a few attributes to attribute together


Node definition
```cpp
template <class LIT> 
/** ^ same thing as tempalte <typename LIT>
 * LIT can be primitive or non-primitive
 */
// The nodes in the linked lists are not contiguous in memory (i.e., they are not right next to each other, like in an array)

struct Node {
    LIT data; // the value stored in the node
    Node* next; // next is the address of another node
    /**
     * Below is the inline constructor with a shorthand 
     * attribute intitialization 
     */
    Node(LIT ndata, Node* nx = NULL): data(ndata), next(nx) {}
}
```



