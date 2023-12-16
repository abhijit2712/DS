Approach 1:
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin() ,strs.end());
        string str = "";

        for(int j=0;j<strs[0].size();j++){
            char ch = strs[0][j];
            for(int i=0;i<strs.size();i++){
                if(ch != strs[i][j]){
                    return strs[0].substr(0,j);
                }
            }
        }
        return strs[0];
        return "";
    }
};



Approach 2:
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin() ,strs.end());
        if(strs.size() == 0) return "";

        int n = strs.size() - 1;
        string str1 = strs[0];
        string str2 = strs[n];
        string ans = "";

        for(int i=0;i<str1.size();i++){
            if(str1[i] == str2[i]){
                ans += str2[i];
            }else break;
        }
        
        return ans;
    }
};
