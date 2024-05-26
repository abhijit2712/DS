class Solution {
public:
    //funtion to swap last and funtion
    //Approach 1: gives  tle

    void swap(vector<int>& nums,int n){        
        int temp = nums[n-1];
        
        for(int i=n-1;i>=1;i--){
            nums[i] = nums[i-1];
        }

        nums[0] = temp;
    }


    void rotate(vector<int>& nums, int k) {
        
       //now using observation
        //take one extra vector
        int n = nums.size();
        k = k % n;
        vector<int> dummy(n,0);
        int j = 0;

        vector<int> temp = nums;

        for(int i=k;i<n;i++){
            dummy[i] = nums[j];
            j++;
        }


        for(int i=0;i<k;i++){
            nums[i] = temp[j];
            j++; 
        }
       

        for(int i=k;i<n;i++){
            nums[i] = dummy[i];
        }

    }
};
