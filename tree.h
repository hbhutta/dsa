#ifndef TREE_H
#define TREE_H

/**
@author: Haad Bhutta

This (binary) tree ADT's implementation (using the Nodes) is hidden from the client.
The public methods are the only things the client can access.

The methods implemented here are inspired by Carrano and Henry's "Data Abstraction & Problem Solving with C++".

Since no constructor Tree() is prototyped here, a default constructor is made available. 
However, this tree will be built just by adding nodes to it.
*/

template <typename T>
class Tree {
    public:
        /**
            Returns true if the binary tree is empty
        */
        bool isEmpty();

        /**
            Returns the height of the binary tree.
            An empty tree will have height of -1,
            since the tree's height is zero-based.
        */
        int getHeight();

        /**
            Returns the number of nodes in the binary tree
        */
        int getNumberOfNodes();

        /**
            Returns the value stored in the root node.
        */
        T getRootData();

        /**
            Sets the value of the root node.
        */
        void setRootData();

        /**
            Adds a given data item to the binary tree.
            Returns true if the removal was successful.
            The number of nodes will be updated.
        */
        bool add (T newData);

        /**
            Removes a given data item from the binary tree.
            Returns true if the removal was successful.
            The number of nodes will be updated
        */
        bool remove(T target);
        void clear();
        void getEntry (Node* visit);
        void contains (Node* visit);
        void preOrderTraverse(Node* visit);
        void inOrderTraverse(Node* visit);
        void postOrderTraverse(Node* visit);


    private: 
        struct Node {
            T data;
            Node* left;
            Node* right;
        };
        Node* root;   
}

#endif