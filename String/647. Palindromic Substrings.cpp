class Solution {
public:
    int countPalindrome(int i,int j,string &s){
        int cnt = 0;

        while(i>=0 && j<s.length() && s[i]==s[j]){
            cnt++;
            i--;
            j++;
        }

        return cnt;
    }

    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;

        for(int i=0;i<n;i++){
            int oddCount  = countPalindrome(i,i,s);
            int evenCount = countPalindrome(i,i+1,s);
            count += oddCount + evenCount;
        }

        return count;
    }
};
