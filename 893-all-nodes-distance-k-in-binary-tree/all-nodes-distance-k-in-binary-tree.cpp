/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*>parent;
    void inorder(TreeNode* root){
        if(!root){
            return;
        }
        if(root->left != NULL){
            parent[root->left] = root;
        }
        if(root->right != NULL){
            parent[root->right] = root;
        }
        inorder(root->left);
        inorder(root->right);
    }

    void bfs( TreeNode* target, int k, vector<int>& result){
        queue<TreeNode*>q;
        q.push(target);

        unordered_set<int> visited;
        visited.insert(target->val);

       
        while(!q.empty()){
            int level = q.size();
            if(k == 0){
                break ;
            }

            while(level--){
                TreeNode* temp = q.front();
                q.pop();

                if(temp -> left && !visited.count(temp->left->val)){
                    q.push(temp->left);
                    visited.insert(temp->left->val);
                }
                if(temp -> right && !visited.count(temp->right->val)){
                    q.push(temp->right);
                    visited.insert(temp->right->val);
                }
                if(parent.count(temp) && !visited.count(parent[temp]->val)){
                    q.push(parent[temp]);
                    visited.insert(parent[temp]->val);
                }
                
            }
            k--;
        }

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            result.push_back(temp->val);
        }
    }


    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        inorder(root);

        bfs( target,k, result);
        return result;
    }
};