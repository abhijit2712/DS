class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = 1e9,maxi = -1e9;

        for(int i=0;i<prices.size();i++){
            mini = min(prices[i] ,mini);

            maxi = max(maxi, {prices[i] - mini});
        }



        return maxi;
    }
};
