#include <iostream>
// #include <Node.h>

// class LinkedList {
//     public:
//         LinkedList(Node* head, Node* tail) {
//             head_ = head;
//             tail_ = tail;
//         }   

//     private:
//         Node* head_;
//         Node* tail_;
// };

class Node {
    public:
        Node(int value, Node* next) { // For single-linked list (one-directional)
            value_ = value;
            next_ = next;
        }

        Node(int value, Node* next, Node* prev) { // For doubly-linked list (bi-directional)
            value_ = value;
            next_ = next;
            prev_ = prev;
        }

    public:
        int value_;
        Node* next_;
        Node* prev_;
};

void printLinkedList(Node* head) { // Works
    Node* node = head;
    while (true) {
        std::cout << node->value_ << std::endl;
        node = node->next_;
        if (node->next_ == nullptr) {
            std::cout << node->value_ << std::endl;
            break;
        }
    }
    std::cout << " " << std::endl;
}

int main() {
    
    Node* tail = new Node(4, nullptr); // Difference between NULL and nullptr?
    Node* right_middle = new Node(3, tail);
    Node* left_middle = new Node(2, right_middle);
    Node* head = new Node(1, left_middle);

    // Print linked list before inserting other nodes
    printLinkedList(head);
    
    // Inserting new_right_middle between right_middle and tail
    Node* new_right_middle = new Node(99, tail);
   
    // Constant time operations (just making the pointer point to something else)
    right_middle->next_ = new_right_middle; // O(1)

    printLinkedList(head);

    return 0;
}