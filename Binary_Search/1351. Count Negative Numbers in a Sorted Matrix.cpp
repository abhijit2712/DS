class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int target = 0;
        

        int cnt = 0;


        for(int i=0;i<grid.size();i++){
            int pos = 0;
            int low = 0,high = grid[i].size() - 1;
            int n = grid[i].size();

            while(low <= high){
                int mid = low + (high - low) / 2;
                
                
                //upper bound
                if(grid[i][mid] >= target){
                    pos = mid;
                    low = mid + 1;
                }else{
                    high = mid - 1;
                }
            }
           // cout << n - pos -1 << endl;
            // if(pos == 0) cnt += n - pos;
            // else 
            cnt += n - high -1;
        }

        return cnt;
    }
};
