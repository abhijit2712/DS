class Solution {
public:
    int hIndex(vector<int>& arr) {
        int n = arr.size();
        if(!n) return 0;
        if(arr[0] == 0 && arr.size() == 1) return 0;
        if(arr.size() == 1) return 1;
        int ans = 0;
        int low = 0,high = arr.size()-1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            int total = n - mid;

            if(total <= arr[mid]){
                ans = total;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return ans;
    }
};
