class Solution {
public:
    int strStr(string s1, string s2) {
        int size = s2.size();
        for(int i=0;i<s1.size();i++){
            string str = s1.substr(i,size);
            if(s2 == str) return i;
        }
        return -1;
    }
};
