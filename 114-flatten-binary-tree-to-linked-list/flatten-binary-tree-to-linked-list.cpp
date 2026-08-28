class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while (curr != NULL) {
            
            // If left subtree exists
            if (curr->left != NULL) {
                
                // Find the rightmost node of left subtree
                TreeNode* pred = curr->left;

                while (pred->right != NULL) {
                    pred = pred->right;
                }

                // Connect right subtree after predecessor
                pred->right = curr->right;

                // Move left subtree to right
                curr->right = curr->left;

                // Left must be NULL
                curr->left = NULL;
            }

            // Move to next node
            curr = curr->right;
        }
    }
};