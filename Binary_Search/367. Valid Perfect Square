class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) return true;
        long long low = 1,high=num/2;

        while(low <= high){
            long long mid = low + (high - low) / 2;
            long long pow = mid * mid;

            if(pow == num) return true;

            if(pow < num){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        return false;
    }
};
