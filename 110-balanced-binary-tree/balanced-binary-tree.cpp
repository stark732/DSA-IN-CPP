class Solution {
public:
    int height(TreeNode* root) {
        if (root == NULL) return 0; // Return 0 for empty nodes
        
        int ll = height(root->left);
        if (ll == -1) return -1; // Propagate left subtree imbalance
        
        int rr = height(root->right);
        if (rr == -1) return -1; // Propagate right subtree imbalance
        
        // Check current node balance
        if (abs(ll - rr) > 1) return -1;
        
        return 1 + max(ll, rr);
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};