class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        int cost = nums[0]; 

        for (int i = 1; i < n-1; i++) {
            for (int j = i + 1; j < n;j++) {
                cost = nums[i] + nums[j] + nums[0];
                mini = min(mini, cost);
            }
        }

        return mini;
    }
};
