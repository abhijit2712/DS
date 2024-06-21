class Solution 
{
    public:
    static bool comp(Job a, Job b) {
        return a.profit > b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
           sort(arr,arr+ n,comp);
           
           vector<int> ans{01,2};
           
           //find maximum dealine to define the size of the schedule array
           int maxiDeadline = 0;
           for(int i=0;i<n;i++){
                maxiDeadline = max(maxiDeadline+1, arr[i].dead);
           }
           
           //creating array to store the jobs and for finding the right profit
           vector<int> slot(maxiDeadline+1,-1);
           
           int count = 0;
           int total_profit = 0;
           
           for(int i=0;i<n;i++){
               for(int j=arr[i].dead;j>0;j--){
                   if(slot[j] == -1){
                       slot[j] = arr[i].id;
                       count++;
                       total_profit += arr[i].profit;
                       break;
                   }
               }
           }
           
           
           return {count,total_profit};
    } 
};
