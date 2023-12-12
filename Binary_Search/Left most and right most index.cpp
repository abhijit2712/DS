//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    long long lower_bound(vector<long long> arr, long long x){
        int n = arr.size();
        long long low =0,high = n-1;
        long long ans = -1;
        
        while(low<=high){
            int mid = (high + low)/ 2;
            if(arr[mid] == x){
                ans = mid;
                high = mid - 1;
            }
            else if(arr[mid] > x){
                high = mid - 1;
            }else{
                 low = mid + 1;
            }
        }
        
        // if(arr[ans] == x) return ans;
        // else return -1;
        
        return ans;
    }
    
    long long upper_bound(vector<long long> arr, long long x){
        int n = arr.size();
        long long low =0,high = n-1;
        long long ans = -1;
        
        while(low<=high){
            int mid = (high + low)/ 2;
             if(arr[mid] == x){
                ans = mid;
                low = mid + 1;
            }
            if(arr[mid] > x){
               
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        
        return ans;
    }
    
    
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        long long l_bound = lower_bound(v,x);
        long long u_bound = upper_bound(v,x);
        //cout << l_bound << "  " << u_bound << endl;
        if(l_bound == -1) return {-1,-1};
        return {l_bound,u_bound};
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends
