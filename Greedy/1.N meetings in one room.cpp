class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>> arr;
        
        for(int i=0;i<n;i++){
            arr.push_back({end[i],start[i]});
        }
        
        sort(arr.begin() , arr.end());
        
        int cnt = 1;
        int prevEnd = arr[0].first;
        for(int i=1;i<arr.size();i++){
            if(arr[i].second > prevEnd){
                prevEnd = arr[i].first;
                cnt++;        
            }
        }
        
        return cnt;
    }
};
