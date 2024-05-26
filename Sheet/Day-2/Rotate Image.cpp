class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dummy(n, vector<int>(n,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dummy[i][j] = matrix[j][i];
            }
            reverse(dummy[i].begin(),dummy[i].end());
        }

        matrix = dummy;
    }
};
