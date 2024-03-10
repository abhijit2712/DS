//Memoization and tabulation
class Solution {
public:
    int dp[450];
    int solve(int index){
        if(index==0) return 1;
        if(index<0) return 0;
        if(dp[index] != -1) return dp[index];
        return dp[index] = solve(index-1) + solve(index-2);
    }

    int climbStairs(int n) {
        memset(dp,0,sizeof(dp));
        //tabulation:
        dp[0] = 0;
        dp[1] = 1;
      
        for(int i=2;i<=n+1;i++){
            dp[i] = dp[i-1] + dp[i-2]; 
        }
      
        return dp[n+1];
    }
};
