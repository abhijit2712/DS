class Solution {
public:
    int last_oc(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0,high = n-1;
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] == target){
                ans = mid;
                low = mid + 1;
            }else if(target > nums[mid]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        return ans;
    }

    int first_oc(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0,high = n-1;
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] == target){
                ans = mid;
                high = mid - 1;
            }else if(target > nums[mid]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int l = first_oc(nums,target);
        int u = last_oc(nums,target);
        return {l,u};
    }
};
