class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int pos = 0,pos2 = 0;
        int last = 0;
        vector<vector<int>> ans;
        int cnt = 0;
        
        for(int i=0;i<nums.size();i++){
            if(i % 3 == 0){ 
                pos = i;
            }else if(i % 3 == 1){
                pos2 = i;
            }
            if(i % 3 == 2){
                if(k >= nums[i] - nums[pos] && k >= nums[i]-nums[pos2]){
                    vector<int> res;
                    res.insert(res.begin(),nums.begin()+pos,nums.begin()+i+1);
                    cnt += i - pos + 1;
                    ans.push_back(res);
                }
            }
        }
        
        
        if(cnt != nums.size()) return {};
        
        
        return ans;
    }
};
