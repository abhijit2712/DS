class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<int> result(n, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int dist = (j-i);
            int Add = min(abs(i-x)+1+abs(j-y) , abs(i-y)+1+abs(j-x));
            int distance = min(dist,Add);
            result[distance-1] += 2; 
        }
    }

    return result;
    }
