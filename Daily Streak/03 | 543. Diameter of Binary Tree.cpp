class Solution {
public:
    int maxi = INT_MIN;
    int f(TreeNode* root){
        if(!root) return 0;

        int left  =  f(root->left);
        int right = f(root->right);

        maxi = max(maxi, left + right);

        return 1 + max(left,right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        f(root);
        return maxi;
    }
};
