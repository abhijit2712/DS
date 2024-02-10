//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string text1, string text2, int n, int m)
    {
        

       // memset(dp,0,sizeof(dp));
        //return solve(n-1,m-1,text1,text2);
       // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int dp[n+1][m+1];
        //base cases
        // for(int j = 0;j<=m;j++) dp[0][j] = 0;
        // for(int i = 0;i<=n;i++) dp[i][0] = 0;

        //bottom up 
        int ans = 0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0||j==0)dp[i][j]=0;
                else if(text1[i-1] == text2[j-1]) {
                    dp[i][j] =  1 + dp[i-1][j-1];
                    ans = max(ans,dp[i][j]);
                }
                else dp[i][j] = 0;
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
