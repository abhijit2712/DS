class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size() == 0) return 0;
        char curr = chars[0];
        int cnt = 1;
        string str = "";

        for(int i=1;i<=chars.size();i++){
            if(i<chars.size() && curr == chars[i]) cnt++;
            else{
                str.push_back(curr);
                if(cnt > 1){
                    string num = to_string(cnt);
                    for(int i=0;i<num.size();i++){
                        str.push_back(num[i]);
                    }
                }
                curr = i < chars.size() ? chars[i] : 0;
                cnt = 1;
            }
        }Ω

        for (int i = 0; i < str.size(); i++) {
            chars[i] = str[i];
        }

        return str.size();
    }
};
