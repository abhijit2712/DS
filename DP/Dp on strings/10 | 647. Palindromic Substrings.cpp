class Solution {
public:
    bool ispalindrome(string s){
        string p = s;
        reverse(p.begin(),p.end());
        if(p == s) return true;
        else return false;
    }


    int countSubstrings(string s) {
        int cnt = 0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                string str = s.substr(i,j+1);
                cout << i << "  " << j << "  "<< str << endl; 
                if(ispalindrome(str)) cnt++;
            }
        }

        return cnt;
    }
};
