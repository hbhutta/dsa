
/**
    @author: Haad Bhutta
    - Note that DFS and BFS will depend on how the graph is implemented
    - They will also work on trees because trees are also graphs 
        - Remember that trees are acyclic graphs
    
    DFS (By height of the graph)
    1. Start at the root node (or any arbitrary node)
    2. If the node started at has neighbours, go to one of them
        - Each time a node is visited, mark it as such
    3. If the current node is the search target, return true and end

    BFS (By width of the graph)
*/

template <typename T>
class Graph {
    public:
        void DFS();
        void BFS();
    private:
        struct Node* { // A vertex/node in the graph

        }
};