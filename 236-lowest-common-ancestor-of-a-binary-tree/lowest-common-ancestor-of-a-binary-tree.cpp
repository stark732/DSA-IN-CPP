class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root,
                                   TreeNode* p,
                                   TreeNode* q) {

        // Base case
        if (root == NULL || root == p || root == q)
            return root;

        // Search in left subtree
        TreeNode* left = lowestCommonAncestor(root->left, p, q);

        // Search in right subtree
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // p and q found in different subtrees
        if (left && right)
            return root;

        // Return whichever side found p or q
        if (left)
            return left;
        else
            return right;
    }
};