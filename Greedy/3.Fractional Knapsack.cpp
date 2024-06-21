class Solution {
  public:
  static bool cmp(Item a,Item b){
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        return r1 > r2;
  }
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
        // vector<int,pair<int,int>> nums;
        
        // for(int i=0;i<n;i++){
        //     int per_one = arr[i].value / arr[i].weight;
        //     nums.push_back({per_one, {arr[i].value,arr[i].weight} });
        // }
        
        // sort(nums.begin(), nume.end() , greater<int>());
        sort(arr, arr+n, cmp);
        int total_weight = w;
        double profit = 0;
        
        for(int i=0;i<n;i++){
            
            // cout << arr[i].value << " "<< arr[i].weight <<"\t" << w << endl;
            int diff = w - arr[i].weight;;
            
            if(w <= 0) return profit;
            
            if(diff < 0){
                int newValue = w;
                double one_value =  (double)arr[i].value / (double)arr[i].weight;
                profit += double(one_value * newValue);
                w -= w;
            }else{
                profit += arr[i].value;
                w -= arr[i].weight;
            }
            
            // cout << profit << endl;
        }
        
        return profit;
    }
};
