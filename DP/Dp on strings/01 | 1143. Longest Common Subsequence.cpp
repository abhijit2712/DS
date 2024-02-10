class Solution {
public:
    //int dp[1001][10001];
    //use same logic as a wild card matching
    //use top down approach to simpliify tabulation further
    // int solve(int i,int j,string &text1,string &text2){
    //     //if i goes to less than 0 return zero beacuse we are counting maximum
    //     if(i<0 || j<0) return 0;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     //check if there is common character in both strings
    //     if(text1[i] == text2[j]){
    //         //do only one call decrease both the index i and j
    //         return dp[i][j] =  1 + solve(i-1,j-1,text1,text2);
    //     }

    //     //do both the call in first call decrease i in second decrease j
    //     //so both goes for all call
    //     return dp[i][j] = max(solve(i-1,j,text1,text2) , solve(i,j-1,text1,text2));
    // }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

       // memset(dp,0,sizeof(dp));
        //return solve(n-1,m-1,text1,text2);
       // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int dp[n+1][m+1];
        //base cases
        // for(int j = 0;j<=m;j++) dp[0][j] = 0;
        // for(int i = 0;i<=n;i++) dp[i][0] = 0;

        //bottom up 
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0||j==0)dp[i][j]=0;
                else if(text1[i-1] == text2[j-1])dp[i][j] =  1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }

        return dp[n][m];
    }
};
