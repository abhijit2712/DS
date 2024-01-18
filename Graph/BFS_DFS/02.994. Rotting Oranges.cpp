class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cntFresh = 0;
        vector<vector<int>> vis(n+1,vector<int> (m+1,0));
        queue<pair<pair<int,int>,int>> q;
  
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2; 
                }

                if(grid[i][j] == 1){
                    cntFresh++;
                }
            }
        }
      
        int maxi = 0;
        int rows[] = {-1,0,1,0};
        int cols[] = {0,1,0,-1};
        int cnt = 0;
      
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int level = q.front().second;
            maxi = max(level,maxi);
            q.pop();

            for(int i=0;i<4;i++){
                int nrow = row + rows[i];
                int ncol = col + cols[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol}, level+1 });
                    vis[nrow][ncol] = 2;
                    cnt++;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] != 2 && grid[i][j]==1) return -1;
            }
        }

        if(cnt != cntFresh) return -1;
      
        return maxi;
    }
};