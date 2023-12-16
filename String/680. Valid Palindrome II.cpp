class Solution {
public:
    bool checkPalindrome(int i,int j,string str) {
           
        while(i <= j){
            if(str[i] != str[j]) return false;
            i++;
            j--;
        }

        return true;
    }

    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while(i <= j){
            if(s[i] != s[j]){
                return (checkPalindrome(i+1,j,s) ||
                checkPalindrome(i,j-1,s));
            }else{
                i++;
                j--;
            }
        }

        return true;
    }
};
