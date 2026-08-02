
class Solution {
public:
    int maxsum;
        int solve(TreeNode* root){
            if(root == nullptr)
                return 0;
                int left = solve(root->left);
                int right = solve(root->right);

            int first = left + right + root->val;

            int second = max(left , right) + root->val;


            int third = root->val;


            maxsum = max({maxsum, first, second, third});

            return max(second, third);
        }

    int maxPathSum(TreeNode* root) {
        maxsum = INT_MIN;

        solve(root);

        return maxsum;
        
    }
};