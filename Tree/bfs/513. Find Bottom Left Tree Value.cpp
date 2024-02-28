class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        //try to code with bfs
        queue<TreeNode*> q;
        q.push(root);
        int val = 0;

        while(!q.empty()){
            int size = q.size();

            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                val = node->val;
                q.pop();

                if(node->right) q.push(node->right);
                if(node->left)  q.push(node->left);
            }
        }


        return val;
    }
};
