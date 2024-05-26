#Approach 1 :

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end());
        int n = intervals.size();
        //Approach -> check last element which is inserted
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        
        int j = 0; 
        for(int i=1;i<n;i++){
            int last_Element = ans[j].back();

            if(last_Element >= intervals[i][0]){
                if(last_Element < intervals[i][1]) ans[j][1] =  intervals[i][1];
            }else{
                ans.push_back(intervals[i]);
                j++;
            }
        }
      
        return ans;
    }
};



#Approach 2:Improvement in the Approach 2st used max funtion to overlapped the interval
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end());
        int n = intervals.size();
        //Approach -> check last element which is inserted
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        int j = 0; 
        for(int i=1;i<n;i++){
            int last_Element = ans[j].back();

            if(last_Element >= intervals[i][0]){
               ans[j][1] =  max(intervals[i][1] , last_Element);
            }else{
                ans.push_back(intervals[i]);
                j++;
            }
        }

        return ans;
    }
};


#Approach 3 :
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergeIntervals;
        if(intervals.size() == 0){
            return mergeIntervals;
        }
        sort(intervals.begin(), intervals.end());
        vector<int> tempInterval = intervals[0];

        for(auto it : intervals){
            if(it[0] <= tempInterval[1]){
                tempInterval[1] = max(it[1], tempInterval[1]);
            }else{
                mergeIntervals.push_back(tempInterval);
                tempInterval = it;
            }
        }

        mergeIntervals.push_back(tempInterval);
        return mergeIntervals;
    }
};
