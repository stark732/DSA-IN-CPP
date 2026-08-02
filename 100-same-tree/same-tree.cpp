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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        queue<TreeNode*>q1;
        queue<TreeNode*>q2;
        if(p == nullptr && q == nullptr)
        return true;
        if(p == nullptr || q== nullptr)
            return false;

        q1.push(p);
        q2.push(q);

        while(!q1.empty() || !q2.empty()){
            TreeNode* node1 = q1.front(); q1.pop();
            TreeNode* node2 = q2.front(); q2.pop();
            if(node1->val != node2->val){
                return false;
            }

            if(node1->left != nullptr && node2 -> left != nullptr){
                q1.push(node1->left);
                q2.push(node2->left);
            }else if(node1->left != nullptr || node2->left != nullptr ){
                return false;
            }
            if(node1->right != nullptr && node2 -> right != nullptr){
                q1.push(node1->right);
                q2.push(node2->right);
            }else if(node1->right != nullptr || node2->right != nullptr ){
                return false;
            }


        }
        return true;
        
    }
};