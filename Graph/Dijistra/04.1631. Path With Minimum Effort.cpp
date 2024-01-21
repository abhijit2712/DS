class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        set<pair<int, pair<int,int>>> st;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        st.insert({0,{0,0}});
        dist[0][0] = 0;

        while(!st.empty()){
            auto it = *(st.begin()); 
            int r = it.second.first;
            int c = it.second.second;

            int diff =  it.first;
        
            st.erase(it);

            int nodeVal = heights[r][c];
            if (r == n - 1 && c == m - 1) return diff;

            for(int i=0;i<4;i++){
                int nrow =  r + delrow[i];
                int ncol =  c + delcol[i];
               
                if(nrow>=0 && nrow<n && ncol<m && ncol>=0){
                    int newEffort = max(abs(heights[nrow][ncol] - nodeVal),diff);
                   
                    if(newEffort < dist[nrow][ncol]){
                        dist[nrow][ncol] = newEffort;
                        st.insert({newEffort,{nrow,ncol}});
                    }

                }
            }

        }

        return 0;        
    }
};
