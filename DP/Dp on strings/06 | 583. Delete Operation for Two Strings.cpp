class Solution {
public:
    int n;
    int m; 
    int longestPalindromeSubseq(string &text1,string &text2,vector<vector<int>> &dp) {
        
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


    string shortestCommonSupersequence(string str1, string str2) {
        n = str1.size();
        m = str2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        int res = longestPalindromeSubseq(str1,str2,dp);

        string ans = "";
        int i=n,j=m;

        while(i>0 && j>0){
            //condtion 1
            if(str1[i-1] == str2[j-1]){
                ans += str1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                ans += str1[i-1];
                i--;
            }else{
                ans += str2[j-1];
                j--;
            }
        }

        while(i>0){
            ans+= str1[i-1];
            i--;
        }
        while(j>0){
            ans+= str2[j-1];
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;

    }
};
