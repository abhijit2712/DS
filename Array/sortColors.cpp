class Solution {
public:
    void sortColors(vector<int>& nums) {
        //Approach 1:
        // sort(nums.begin(), nums.end());


        //Approach 2 : 
        int cnt__one =0,cnt_two = 0,cnt_zero = 0;


        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                cnt_zero++;
            }else if(nums[i] == 1){
                cnt__one++;
            }else{
                cnt_two++;
            }
        }

        vector<int> ans;
        int i = 0;
        while(cnt_zero--){
            nums[i] = 0;
            i++;
        }

        while(cnt__one--){
            nums[i] = 1;
            i++;
        }

        while(cnt_two--){
            nums[i] = 2;
            i++;
        }
        
    
    }   
};
