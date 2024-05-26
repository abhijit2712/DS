class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Approach 1:
        // int n = nums.size();
        // vector<int> freq(n,0);
        // for(int i=0;i<nums.size();i++){
        //     freq[nums[i]]++;

        //     if(freq[nums[i]] > 1) return nums[i];
        // }
        // return -1;

        //Approach 2 : using the sort array
        // int n = nums.size();
        // sort(nums.begin() , nums.end());
        // for(int i=0;i<n-1;i++){
        //     if(nums[i] == nums[i+1]){
        //         return nums[i];
        //     }
        // }

        // return -1;


        //Approach 3:
        // unordered_map<int,int> mpp;
        // int n = nums.size();
        // for(int i=0;i<n;i++){
        //     if(mpp[nums[i]] == 1) return nums[i];
        //     mpp[nums[i]] = 1;
        // }

        // return -1;


        //Approach 4 :
        int slow = nums[0],fast=nums[nums[0]];

        while(slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        	slow = 0;

            while(slow != fast){
                slow = nums[slow];
                fast = nums[fast];
            }

        return slow;
    }
};
