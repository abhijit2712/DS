class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0;
        int n = letters.size();
        int high = n-1;
        char ans = letters[0];

        while(low <= high){
            int mid = (high + low) / 2;

            if(letters[mid] >target){
                ans = letters[mid];
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return ans;

    }
};
