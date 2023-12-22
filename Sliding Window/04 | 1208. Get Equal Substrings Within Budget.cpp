Approach 1:
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int head = 0,tail = 0, ans = 0,sum = 0;

        for(head=0;head<s.size();head++){
            sum += abs(s[head] - t[head]);

            while(sum > maxCost){
                sum -=  abs(s[tail] - t[tail]);;
                tail++;
            }
            ans = max(ans,head - tail + 1); 
        }

        return max(ans,head - tail); 
    }
};


Approach 2 : 
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int head = 0,tail = 0, ans = 0,sum = 0;

        for(head=0;head<s.size();head++){
            sum += abs(s[head] - t[head]);

            while(sum > maxCost){
                sum -=  abs(s[tail] - t[tail]);;
                tail++;
            }
            ans = max(ans,head - tail + 1); 
        }

        return ans; 
    }
};
