class Solution {
public:
    int characterReplacement(string s, int k) {
        int head = 0,tail=0,ans= 0;
        vector<int> freq(26,0);

        for(head=0;head<s.size();head++){
            freq[s[head] - 'A']++;

            while((head-tail+1) - *max_element(freq.begin(),freq.end()) > k){
                freq[s[tail] - 'A']--;
                tail++;
            }

            ans = max(ans, head-tail+1);
        }

        return ans;
    }
};
