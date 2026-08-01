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

    /*void inorder(TreeNode* root , vector<int>&ans){
        if(root== nullptr)
        return;

        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }*/

    vector<int> inorderTraversal(TreeNode* root) {
        /*
        stack<TreeNode*>st;
        stack<bool>visited;
        st.push(root);
        visited.push(0);
        vector<int>ans;
        if (root == nullptr)
        return ans;

        while(!st.empty()){
            TreeNode* temp = st.top();
            st.pop();
            bool flag = visited.top();
            visited.pop();

            if(flag == 0){
                if(temp->right)
                {
                st.push(temp->right);
                visited.push(0);
                }

                if(temp){
                    st.push(temp);
                    visited.push(1);
                }

                if(temp->left){
                    st.push(temp->left);
                    visited.push(0);
                }
            }

           else{
            ans.push_back(temp->val);
           }
        }
        return ans;
*/

// method 2 recusion;

    /*vector<int>ans;
    inorder(root, ans);
    return ans;*/

    // method 3 morris

    vector<int>ans;
    while(root){
        if(!root->left){
            ans.push_back(root->val);
            root = root->right;
        }else{
            TreeNode* curr = root->left;

            while(curr->right && curr->right != root)
                curr = curr->right;

                if(curr->right == nullptr){
                    curr->right = root;
                    root = root->left;
                }else{
                    curr->right = nullptr;
                    ans.push_back(root->val);
                    root =root ->right;
                }
            
        }
    }

    return ans;
    }
};