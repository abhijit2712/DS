class Solution {
public:
    int solve(TreeNode* root,int cnt){
        if(!root) return cnt;
        return max(solve(root->left,cnt+1) , solve(root->right,cnt+1));
    }

    int maxDepth(TreeNode* root) {
        int maDepth = 0;
        return solve(root,0);
    }
};
