class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int head = 0,tail=0,ans = 0,sum=0;
        map<int,int> mpp;

        for(head=0;head<nums.size();head++){
            mpp[nums[head]]++;

            while(mpp[nums[head]] > 1){
                //ans = max(ans,sum);
                sum -= nums[tail];
                mpp[nums[tail]]--;
                tail++;
            }
            if(mpp[nums[head]] == 1) sum += nums[head];
           ans = max(ans,sum);
        }

        return ans;
    }
};
