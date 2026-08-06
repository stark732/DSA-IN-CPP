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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        stack<TreeNode *>s1,s2;
        vector<vector<int>>ans;
        if(root == nullptr)
            return ans;

        s1.push(root);

        while(!s1.empty() || !s2.empty()){
            vector<int>level;
             while(!s1.empty()){
                 TreeNode* Node = s1.top();
                s1.pop();
                level.push_back(Node->val);
                if(Node->left)
                s2.push(Node->left);
                if(Node->right)
                s2.push(Node->right);
            }
            if(!level.empty())
            ans.push_back(level);
            level.clear();

            while(!s2.empty()){
                TreeNode* Node = s2.top();
                s2.pop();
                level.push_back(Node->val);

                if(Node->right)
                    s1.push(Node->right);
                if(Node->left)
                    s1.push(Node->left);
            }
            if(!level.empty())
                ans.push_back(level);
            
            level.clear();
        }
        return ans;
        
    }
};