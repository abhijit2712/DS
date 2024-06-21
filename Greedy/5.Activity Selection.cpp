class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int,int>> arr;
        
        for(int i=0;i<n;i++){
            arr.push_back({end[i] , start[i]});
        }
        
        sort(arr.begin() , arr.end());
        
        int startpoint = arr[0].second; 
        int endpoint = arr[0].first;
        int cnt = 1;
        for(int i=1;i<n;i++){
            if(endpoint < arr[i].second){
                endpoint = arr[i].first;
                cnt++;
            }    
        }
        
        return cnt;
    }
};
