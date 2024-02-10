class Solution {
public:
    bool f(int i,int j,string s,string p,vector<vector<int>> &dp){
        if(i==s.size() && j==p.size()) return true;

        if(i>=s.size()){
            while(j<p.size()){
                if(p[j] != '*') return false;
                j++;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(p[j] == '*'){
            return dp[i][j] = f(i,j+1,s,p,dp) || f(i+1,j,s,p,dp);
        }else if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j] =  f(i+1,j+1,s,p,dp);
        }
        

        return dp[i][j] =  false;
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,-1));
        return f(0,0,s,p,dp);
    }
};
