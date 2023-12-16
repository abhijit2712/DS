class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> mpp;
        for(int i=0;i<strs.size();i++){
            string str = strs[i];
            sort(str.begin() ,str.end());
            mpp[str].push_back(strs[i]);
        }
        
        vector<vector<string>> ans;
        for(auto it : mpp){
            vector<string> res;
            for(auto x : it.second) res.push_back(x);
            ans.push_back(res);
         }

        return ans;
    }
};
