struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) { // 10 min
        if (root == nullptr) {
            return root;
        }
        if (root->val == key) {
            
        } else {
            deleteNode(root->left, key);
            deleteNode(root->right, key);
        }
        return root;
    }

    /**
     * The successor and predecessor are guaranteed to be leaf nodes
    */
    TreeNode* findSuccessor(TreeNode* node) { // Smallest element in right ST
        TreeNode *current = node->right, *succ = nullptr;
        while (current != nullptr) { 
            if (current->left == nullptr) return current;
            current = current->left;
        }
        return current;
    }

    TreeNode* findPredecessor(TreeNode* node) { // Largest element in left ST
        TreeNode *current = node->left; // Start from the left ST
        while (current != nullptr) {
            if (current->right != nullptr) {
                current = current->right;
            } 
            // else {
            //     current = current->left;
            // }
        }
        return current;
    }
};
