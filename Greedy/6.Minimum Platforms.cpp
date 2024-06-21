class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        if(n == 0) return 0;
    	vector<pair<int,int>> nums;
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	
    	int i = 1;
    	int j = 0;
    	int cnt = 1;
    	int maxi = 1;
    	
    	while(i < n && j < n){
    	    if(arr[i] <= dep[j]){
    	        cnt++;
    	        i++;
    	    }else {
    	        cnt--;
    	        j++;
    	    }
    	    maxi = max(cnt, maxi);
    	}
    	
    	return maxi;
    }
};
