class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int val = -1e9;

        int ptr = 0;
        for(int i=0;i<nums.size();i++){
            if(val != nums[i]){
                nums[ptr] = nums[i];
                ptr++;
                val = nums[i];
            }
        }

        return ptr;
    }
};
