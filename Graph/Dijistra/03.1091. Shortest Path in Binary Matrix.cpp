class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();


        if(n==1 and grid[0][0]==0) return 1;
        if(grid[0][0]==1 ||grid[n-1][n-1]==1) return -1;

        queue<pair<pair<int,int>,int>> st;
        vector<vector<int>>vis (n+1,vector<int>(n+1,0));
        
        if(grid[0][0] == 0){
            st.push({{0,0},1});
        }

        int delrow[] = {-1,-1,-1,0,0,1,1,1};
        int delcol[] = {-1,0,1,-1,1,-1,0,1};
        int cnt = 0;
        int mini = INT_MAX;
        
        while(!st.empty()){
            auto stTop = st.front();
            int row = stTop.first.first;
            int col = stTop.first.second;
            int rootNode = stTop.second;
            cnt = rootNode;
            st.pop();

            for(int i=0;i<8;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n &&!vis[nrow][ncol] && grid[nrow][ncol]==0){
                if(nrow==n-1 && ncol==n-1) mini=min(mini,cnt+1);
                vis[nrow][ncol] = true;
                st.push({{nrow,ncol},cnt+1});
            }
            }
        }
        
        
        if(mini == INT_MAX) return -1;
        return mini;
        }
};
