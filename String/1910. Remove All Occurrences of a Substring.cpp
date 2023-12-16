class Solution {
public:
    bool possible(stack<char> st,string part){
        int n2 = part.length();
        int j = n2-1;
        while( j >=0 and st.top() == part[j]){
            st.pop();
            j--;
        }
        return (j == -1);
    }


    string removeOccurrences(string s, string part) {
        int m = part.size();
        stack<char> st;

        for(int i=0;i<s.size();i++){
            st.push(s[i]);

            if(st.size() >= m){
                if(possible(st,part)){
                    int count = m;
                    while(count--){
                        st.pop();
                    }
                }
            }
        }

        string res= "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
