class Solution {
public:
  
    // int solve(int index,vector<int>& nums,int target){
    //     if(target == 0) return 1;
    //     if(index >= nums.size()) return 0;
    //     if(target < 0) return 0;

    //     //2d : dp
    //     if(dp[index][target] != -1) return dp[index][target];

    //     //use for loop to itrate same number again and again
    //     int ways = 0;
    //     for(int i=0;i<nums.size();i++){
    //         ways += solve(i,nums,target - nums[i]);
    //     }
    //     return dp[index][target] = ways;
    // }

    int combinationSum4(vector<int>& nums, int target) {
       // memset(dp,0,sizeof(dp));
        //return solve(0,nums,target);
        // int n= nums.size();
        // vector<int> dp(t+1,0);
        // //tabulation: 
        // //base case 1 : target 0 hua konse bhi index pe to return 1 karna
        // dp[0] = 1;

       
        // for(int target=1;target<=t;target++){
        //         for(int index=0;index<nums.size();index++){
              
        //         if(target - nums[index] >= 0){
        //             dp[index] += dp[target - nums[index]];
        //         }

        //     }
        // }


        // return dp[t];

        vector< unsigned int> dp(target+1);
        dp[0]=1;
        
        for(int i=1; i<target+1; i++)
            for(int j=0; j<nums.size(); j++)
                if(nums[j]<=i)
                    dp[i] += dp[i-nums[j]];
        
        return dp[target];
    }
};
