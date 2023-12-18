class Solution {
public:
    
    
bool isPalindromic(int x) {
    string str = to_string(x);
    string revStr = str;
    reverse(revStr.begin(), revStr.end());
    return str == revStr;
}

long long findPalindromeLessThan(int median, const vector<int>& nums) {
    long long palindrome = 0;
    for (int i = median; i >= 0; --i) {
        if (isPalindromic(i)) {
            palindrome = i;
            break;
        }
    }
    return palindrome;
}

long long findPalindromeGreaterThan(int median, const vector<int>& nums) {
    long long palindrome = 0;
    for (int i = median; i <= 1e9; ++i) {
        if (isPalindromic(i)) {
            palindrome = i;
            break;
        }
    }
    return palindrome;
}
    
long long minimumCost(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int median = nums[n / 2];
    long long palindromeLess = findPalindromeLessThan(median, nums);
    long long palindromeGreater = findPalindromeGreaterThan(median, nums);
    
    long long costLess = 0;
    long long costGreater = 0;

    for (long long num : nums) {
        costLess += abs(num - palindromeLess);
        costGreater += abs(num - palindromeGreater);
    }

    return min(costLess, costGreater);
    }
};
