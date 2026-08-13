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
    int widthOfBinaryTree(TreeNode* root) {
         unsigned long long ans = 0;
        if(!root){
            return ans;
        }
        queue<pair<TreeNode*, unsigned  long long >> q;
        q.push({root,0});
       
        while(!q.empty()){
            int qsize = q.size();
            unsigned long long first = q.front().second ;
            unsigned long long last = q.back().second;

            ans = max(ans, last-first+1);
            for(int i = 0; i<qsize;i++){
                auto temp = q.front();
                q.pop();

                if(temp.first->left){
                    q.push({temp.first->left, temp.second*2+1});
                }
                if(temp.first->right){
                    q.push({temp.first->right, temp.second*2+2});
                }
            }
        }
        return ans;
    }
};