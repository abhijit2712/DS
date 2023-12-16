class Solution {
public:
    string palindromeLenght(int i,int j,string &s){
        while(i>=0 && j<s.size() && s[i]==s[j]){
            i--;
            j++;
        }
        int size = (j-1) - (i+1)  + 1; 
        string str = s.substr(i+1,size); 
        return str;
    }

    string longestPalindrome(string s) {
        int maxi = 0;
        string ans = "";

        for(int current=0;current<s.size();current++){
            string str1 = palindromeLenght(current,current,s);
            if( maxi < str1.size()){
                ans = str1;
                maxi = str1.size();
            }
            str1 = palindromeLenght(current,current+1,s);
            if(maxi < str1.size()){
                ans = str1;
                maxi = str1.size();
            }
        }
        return ans;
    }
};
