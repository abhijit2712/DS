class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size() - 1;

        set<char> st{'a','e','i','o','u','A','E','I','O','U'};
        char ch ,lastch;
        
        while(i <= j){
            ch = s[i];
            lastch = s[j];

            if(st.find(ch)== st.end() && st.find(lastch)==st.end()){
                i++;
                j--;
            }
            else if(st.find(ch) == st.end()){
                i++;
            }
            else if(st.find(lastch) == st.end()){
                j--;
            }else{
                swap(s[i],s[j]);
                i++;
                j--;
            }
        }

        return s;
    }
};
