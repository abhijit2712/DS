App 1 : prefix sum
class Solution {
public:
    int maxScore(string s) {
       
        int zeroCount = 0;
        int oneCount  = 0;
        int n = s.size();
        vector<int> prefixZero(n,0);
        vector<int> prefixOne(n,0);
        int flag0 = 0;
        int flag1 = 0; 

        for(int i=0;i<s.size();i++){
            if(s[i] == '0'){
                flag0=1;
                zeroCount++;
            }
            if(s[n-i-1] == '1'){
                 flag1=1; 
                 oneCount++;
            }            
            prefixZero[i] = zeroCount;
            prefixOne[n-i-1] = oneCount;
        }

    
        int mini = 0;
        for(int i=0;i<prefixZero.size()-1;i++){
            mini = max(mini, prefixZero[i] + prefixOne[i+1]);
        }

        return mini;
    }
};

Approach 2:
class Solution {
public:
    int maxScore(string s) {
        int ans=INT_MIN;
        int ones=0,zeros=0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='1'){
                ones++;
            }
            else{
                zeros++;
            }
            ans=max(ans,zeros-ones);
        }
        if(s[s.size()-1]=='1')
        ones++;

        return ans=ans+ones;

    }
};
