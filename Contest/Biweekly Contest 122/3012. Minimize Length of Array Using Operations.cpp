class Solution {
public:
    int minimumArrayLength(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int len = arr.size();
        
        if(len>2 && arr[0]!=arr[1])  return 1;
        
         int gcd = arr[0];
        for(auto i:arr){
            gcd = __gcd(gcd,i);
        }
        int cntr = 0;
        
        for(auto i:arr)
            if(i == gcd) cntr++;

        return max(1,(cntrt+1)/2);
    }
};
