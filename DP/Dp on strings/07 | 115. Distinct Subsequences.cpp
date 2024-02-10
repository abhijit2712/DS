class Solution {
public:

    #define ll long long
    int dp[1001][10001];
    // use same logic as a wild card matching
    // use top down approach to simpliify tabulation further
    int solve(int i,int j,string text1,string text2){
        //if i goes to less than 0 return zero beacuse we are counting maximum
        if(j<0) return 1;
        if(i<0) return 0;
        

        if(dp[i][j] != -1) return dp[i][j];

        //check if there is common character in both strings
        if(text1[i] == text2[j]){
            //do only one call decrease both the index i and j
            return dp[i][j] =  solve(i-1,j-1,text1,text2) 
            + solve(i-1,j,text1,text2);
        }

        //do both the call in first call decrease i in second decrease j
        //so both goes for all call
        return dp[i][j] = solve(i-1,j,text1,text2);
    }

    int numDistinct(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        // memset(dp,-1,sizeof(dp));
        // return solve(n-1,m-1,s,t);
        vector<vector<unsigned long long>> dp(n+1,vector<unsigned long long>(m+1,0));


        //base case
        for(int i=0;i<=n;i++){
            dp[i][0] = 1;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] =  dp[i-1][j-1] + dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }



        return (int) dp[n][m];
    }
};
