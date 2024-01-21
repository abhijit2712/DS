class Solution {
    static bool cmpt(pair<char,int> a,pair<char,int> b){
        return a.second > b.second; 
    }
    
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<pair<char,int>> res;
        map<int,int> mpp;
        
        for(int i=0;i<n;i++){
            mpp[word[i]]++;
        }
        
        for(auto it : mpp){
            res.push_back({it.first,it.second});
        }
        
        sort(res.begin(),res.end(),cmpt);
        
      
        
       
        map<char,int> mpp2;
        
        for(int i=0;i<res.size();i++){
            int size = mpp2.size();
            char ch = res[i].first;
            
            if(size < 8){
                mpp2[ch] = 1;
            }else if(size < 16){
                mpp2[ch] = 2;
            }else if(size < 24){
                mpp2[ch] = 3;
            }else{
                mpp2[ch] = 4;
            }
        }
        
        int cnt = 0;
        
        for(int i=0;i<res.size();i++){
            cnt += mpp2[res[i].first] *  res[i].second;    
        }
        
        return cnt;
    }
};
