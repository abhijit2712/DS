class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int head = 0,tail = 0,ans = INT_MAX,sum=0;

        for(head=0;head<nums.size();head++){
            sum += nums[head];
            
            while(sum >= target){
                ans = min(ans, head-tail+1);
                sum -= nums[tail];
                tail++;
            }

        }
        if(ans == INT_MAX) return 0;

        return min(ans,head-tail+1);
    }
};
