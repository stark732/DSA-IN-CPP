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
    int ans = -1;
    int count = 0;
    void solve(TreeNode* root, int k){
        if(root == NULL) return;
        solve(root->left, k);

        count++;

        if(count == k){
           ans = root->val;
            return;
        }
        solve(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
       /* stack<TreeNode*> st;
        TreeNode* curr = root;

        while(true){
            while(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }
            
            curr = st.top();
            st.pop();

            k--;

            if(k == 0){
                return curr->val;
            }

            curr = curr->right;
        }*/

        solve(root, k);
        return ans;
    }
};