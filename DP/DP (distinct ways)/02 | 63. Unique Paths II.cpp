//memoization 

int dp[101][101];
    int solve(int i,int j,vector<vector<int>>& obstacleGrid){
        //base cases:
        if(i==0 && j==0 && obstacleGrid[i][j]==0) return 1;
        if(i<0 || j<0 || obstacleGrid[i][j]==1) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        //left
        int left = solve(i,j-1,obstacleGrid);
        //up
        int up = solve(i-1,j,obstacleGrid);

        return dp[i][j] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        memset(dp,0,sizeof(dp));
        // return solve(n-1,m-1,obstacleGrid);
    }

//tabulation : 
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        memset(dp,0,sizeof(dp));
        // return solve(n-1,m-1,obstacleGrid);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0 && obstacleGrid[i][j]==0) dp[i][j] = 1;
                else if(obstacleGrid[i][j]==1) dp[i][j] = 0;
                else{
                //left
                int left = 0, up = 0;
                if(j > 0) left = dp[i][j-1];
                if(i > 0) up   = dp[i-1][j];

                dp[i][j] = left + up;
                }
            }
        }

        return dp[n-1][m-1];
    }

