class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //can use the technique of marking  
        //like a visited array
        int n = matrix.size();
        int m = matrix[0].size();
        ///use like a branch and bound of a n queen 

        vector<int> rows(n,0);
        vector<int> cols(m,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 0){
                    rows[i] = 1;
                    cols[j] = 1;
                }
            }
        }

        for(int i=0;i<n;i++){
            if(rows[i] == 1){
                vector<int> dummy(m,0);
                matrix[i] = dummy;
            }
        }



        for(int j=0;j<m;j++){
            if(cols[j] == 1){
                for(int i=0;i<n;i++){
                    matrix[i][j] = 0;
                }
            }
        }

    }
};
