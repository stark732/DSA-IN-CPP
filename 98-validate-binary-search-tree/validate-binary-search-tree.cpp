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
    bool inorder(TreeNode* root,long long &previous){
        if(!root){
            return 1;
        }

        if(!inorder(root->left, previous)){
            return 0;
        }

        if(root->val <= previous)
        return 0;

        previous = root->val;

        return inorder(root->right, previous);
    }


    bool isValidBST(TreeNode* root) {

        long long previous = LLONG_MIN;

        return inorder (root, previous);
        
    }
};