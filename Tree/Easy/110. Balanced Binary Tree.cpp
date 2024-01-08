class Solution {
public:
    int height(TreeNode* root){
        if(!root) return 0;
        return  1 + max(height(root->left),height(root->right));
    }

    bool solve(TreeNode* root){
        if(!root) return true;
        int diff = abs(height(root->left) - height(root->right));
        if(diff > 1) return false;
        return (solve(root->left) && solve(root->right));
    }

    bool isBalanced(TreeNode* root) {
        return solve(root);
    }
};
