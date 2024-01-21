class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        vector<int> res = nums;
        sort(res.begin(),res.end());
        vector<int> Bits(nums.size(),0);
        
        
        for(int i=0;i<nums.size();i++){
            int num = nums[i];
            int count = 0;
            while (num) {
                count += num & 1;
                num >>= 1;
            }
            Bits[i] = count;
        }
        int bit = Bits[0];
        int bitIndex = 0;
        
        for(int i=1;i<Bits.size();i++){
            if(bit == Bits[i]) continue;
            else{
                sort(nums.begin()+bitIndex,nums.begin()+i);
                bitIndex = i;
                bit = Bits[i];
            }
        }
        
        sort(nums.begin()+bitIndex,nums.end());
       
        return res == nums;
    }
};
