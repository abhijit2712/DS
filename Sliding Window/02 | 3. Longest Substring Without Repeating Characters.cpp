Approach 1:
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int ans=0,head=0,tail=0;

        for(head=0;head<s.size();head++){
            mp[s[head]]++;

            while(mp[s[head]] > 1){
                mp[s[tail]]--;
                tail++;
                //ans = max(head-tail+1,ans);
            }
            ans = max(head-tail+1,ans);
        }
        return ans;
    }
};


Approach 2: size is updated before tail increament
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int ans=0,head=0,tail=0;

        for(head=0;head<s.size();head++){
            mp[s[head]]++;

            while(mp[s[head]] > 1){
                mp[s[tail]]--;
                tail++;
                ans = max(head-tail+1,ans);
            }
           ans = max(head-tail+1,ans);
        }

        return ans;
    }
};
