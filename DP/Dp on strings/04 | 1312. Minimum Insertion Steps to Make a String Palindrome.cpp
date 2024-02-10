class Solution {
public:
    int longestPalindromeSubseq(string text1) {
        int n = text1.size();
        int m = text1.size();
        string text2 = text1;
        reverse(text2.begin(),text2.end());
       // memset(dp,-1,sizeof(dp));
       // return solve(n-1,n-1,s,t);

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


    int minInsertions(string s) {
        int n = s.size();
        int lcs = longestPalindromeSubseq(s);
        return n - lcs; 
    }
};
