class Solution {
public:
    bool isPalindrome(string s) {
       
        string str = "";
        for(int i=0;i<s.size();i++){
            if(isalpha(s[i]) || (s[i]>='0' && s[i]<='9')){
                str += tolower(s[i]);
            }
        }

        cout << str << "  ";

        int i = 0;
        int j = str.size() - 1;

        while(i <= j){
            if(str[i] != str[j]) return false;
            i++;
            j--;
        }

        return true;
    }
};
