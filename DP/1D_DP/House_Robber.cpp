class Solution {
public:
    int f(int index,vector<int> & nums,vector<int> &dp){
        //base case
        if(index < 0) return 0;
        if(dp[index] != -1) return dp[index];

        //take and not_take pattern
        int take = 0,not_take=0;

        take =  nums[index] + f(index-2,nums,dp);

        not_take = f(index-1,nums,dp);

        return dp[index] = max(take, not_take);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        int take = 0,not_take=0;

        vector<int> dp(n+1,0);
        // return f(n-1,nums,dp);

        //make tabulation 
        // for(int index=0;index<n;index++){
        //     take = nums[index];
        //     if(index-2>=0) take +=  dp[index-2];
        //     if(index-1>=0) not_take = dp[index-1];
        //     dp[index] = max(take, not_take);
        // }

        
        //space optimization : 
        int prev = 0,prev2=0;
        for(int i=0;i<n;i++){
            take = nums[i];
            if(i-2>=0) take +=  prev2;
            if(i-1>=0) not_take = prev;
            prev2 = prev;
            prev = max(take, not_take);
        }


        return prev;
    }
};
