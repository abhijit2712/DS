class Solution {
  public:
    int n;
    int m;
    
    void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>> &vis,
    vector<pair<int,int>> &vec,int originalRow,int originalCol){
        
        //mark row and col
        vis[row][col] = 1;
        vec.push_back({row-originalRow, col-originalCol});
        
        int delrow[] = {-1, 0 ,1 ,0};
        int delcol[] = {0, 1, 0, -1};
        
        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                dfs(nrow,ncol,grid,vis,vec,originalRow,originalCol);
            }
        }
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
       n = grid.size();
       m = grid[0].size();
       
       vector<vector<int>> vis(n,vector<int>(m,0));
       set<vector<pair<int,int>>> st;
     
       
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    vector<pair<int, int>> vec; 
                    dfs(i,j,grid,vis,vec,i,j);
                    st.insert(vec); 
                }    
           }
       }
       
       return st.size();
    }
};
