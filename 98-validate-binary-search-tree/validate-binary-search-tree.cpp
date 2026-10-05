/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool inorder(TreeNode* node, long long & previous){
        if(node == NULL)
            return true;
        
        
        if(!inorder(node->left, previous)){
            return false;
        }

        if(node->val <= previous)
            return false;
        
        previous = node->val;
        
        return inorder(node -> right, previous);
    }

    bool isValidBST(TreeNode* root) {
        long long previous = LLONG_MIN;

        return inorder(root, previous);
    }
};