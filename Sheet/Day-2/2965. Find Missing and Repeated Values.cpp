class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;

        int sum = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                ans.push_back(grid[i][j]);
                sum += grid[i][j];
            }
        }

        int n = ans.size();
        sort(ans.begin(),ans.end());
        
        int repeated = 0;

        for(int i=0;i<n-1;i++){
            if(ans[i] == ans[i+1]){
                repeated = ans[i];
            }
        }

        
        int missing_no = 0;
        int total_sum = n * (n+1) / 2;
        sum = sum - repeated;
        cout << total_sum << endl;
       
       missing_no = total_sum - sum;



        return {repeated,missing_no};
    }
};
