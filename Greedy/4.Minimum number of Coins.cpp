class Solution{
public:
    vector<int> minPartition(int N)
    {
        // code here
        vector<int> arr  {2000,500,200,100,50,20,10,5,2,1};
        vector<int> nums {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        
        int index = 0;
        for(int i=0;i<nums.size();i++) if(nums[i] == N) return {N};
        
        
        for(int i=0;i<arr.size();i++){ //need to break
            if(nums[i] < N) {
                //store the index
                index = i;
            }else break;
        }
        
        vector<int> ans;
        for(int i=index;i>=0;i--){
            while(N >= nums[i]){
                N -= nums[i];
                ans.push_back(nums[i]);
                
            }
        }
        
        return ans;
    }
};
