#include <Node.h>

/**
 * Template is used since the value is not just restricted to integers,
 * they could be chars, bools, floats, or even non-primitive Types, for example.
 * 
 * But it would be pointless for typename T to be Node, it could be anythin else.
*/
template <typename T>

/**
 * The Node struct definition would have to be different 
 * for singly and doubly linked lists, so maybe the approach 
 * of making subclasses from a class called LinkedList would not work...?
*/
class LinkedList {
    public:
        LinkedList(T value_, Node* next_) {
            value = value_;
            next = next_;
        }

        LinkedList(T value_, Node* prev_, Node* next_) {
            value = value_;
            prev = prev_;
            next = next_:
        }

        void printLinkedList(Node* head, bool isForward) {
            Node* node = head;
            if (isForward) {
                while (node.)
            }
        }

    public:
        T value;
        Node* next;
        Node* prev;
};
