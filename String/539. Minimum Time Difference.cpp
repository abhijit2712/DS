class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;

        //step 1 : convert time string to minutes 
        for(int i=0;i<timePoints.size();i++){
            string curr = timePoints[i];
            int hours  = stoi(curr.substr(0,2));
            int minute = stoi(curr.substr(3,2)); 

            int totalMinutes = (hours * 60 + minute);
            minutes.push_back(totalMinutes);
        }

        //step 2 : Sort
        sort(minutes.begin(),minutes.end());


        //step 3 : Find difference 
        int mini = INT_MAX;
        int n = minutes.size();

        for(int i=0;i<n-1;i++){
            int diff = minutes[i+1] - minutes[i];
            mini = min(mini,diff);
        }

        //step 4 : 00:00 test case will be gone wrong 
        //to fix this test case
        int lastDiff = (minutes[0] + 1440) - minutes[n-1];
        mini = min(mini , lastDiff);
        

        //step 5 : return the mini
        return mini; 
    }
};
