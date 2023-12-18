class Solution {
public:
    static bool mycomp(string a,string b){
        string t1 = a+b;
        string t2 = b+a;

        return t1 > t2;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> snums;
        string ans = "";
        for(auto num : nums){
            snums.push_back(to_string(num));
        }

        sort(snums.begin(),snums.end(), mycomp);

        if(snums[0] == "0") return "0";

        for(auto str : snums){
            ans += str;
        }

        return ans;
    }
};
