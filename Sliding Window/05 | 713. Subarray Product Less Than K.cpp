class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int head = 0,tail=0,ans = 0,prod = 1;

        for(head=0;head<nums.size();head++){
            prod *= nums[head];

            while(prod >= k){
                prod /= nums[tail];
                tail++;
            } 
            ans += (head - tail + 1);
        }
       
        if(ans<0)return 0;
        
        return ans;
    }
};

logic : counting using the size of window
