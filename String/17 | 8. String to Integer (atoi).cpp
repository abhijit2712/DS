Approach 1: 
class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        long long result = 0;
        int i = 0;

        for(i=0;i<s.size();i++){
            if(s[i] != ' ') break;
        }

        if(s[i]=='+' || s[i]=='-'){
            if(s[i]=='-') sign = -1;
            else sign = 1;
            i++;
        }

        while(i<s.size() && isdigit(s[i])){
            result = (result*10) + (s[i++] - '0'); 
            if(result*sign >= INT_MAX) return INT_MAX;
            if(result* sign <= INT_MIN) return INT_MIN;
        }

        return result * sign;
    }
};



Approach 2 : 
class Solution {
public:
    int myAtoi(string s) {
        int number = 0;
        stringstream ss(s);
        ss >> number;
        return number;
    }
};
