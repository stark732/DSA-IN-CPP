
class Solution {
public:
 
    int  height(TreeNode* root){
        if(root==NULL) return NULL;
        int ll=height(root->left);
        int rr=height(root->right);
        return max(ll,rr)+1;

    }
    int maxDepth(TreeNode* root) {
       return height(root);

        
    }
};