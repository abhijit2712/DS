class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        map<char,int> mp;
        
        for(int i=0;i<n;i++){
            int size = mp.size();
            char ch = word[i];
            
            if(size < 8){
                mp[ch] = 1;
            }else if(size < 16){
                mp[ch] = 2;
            }else if(size < 24){
                mp[ch] = 3;
            }else{
                mp[ch] = 4;
            }
        }
        
        int cnt = 0;
        
        for(int i=0;i<n;i++){
            cnt += mp[word[i]];    
        }
        
        
        return cnt;
    }
};
