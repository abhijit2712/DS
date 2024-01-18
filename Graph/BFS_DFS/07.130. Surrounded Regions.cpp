class Solution {
public: 

    int n;
    int m;
    void dfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>> &vis,int delrow[],int delcol[]){
        vis[row][col] = 1;

        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='O' && !vis[nrow][ncol]){
                  dfs(nrow,ncol,grid,vis,delrow,delcol);
            }
        }

    }

    void solve(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();



        //create 2 arrays for direction change
        int delrow[] = {-1, 0 ,1 ,0};
        int delcol[] = {0, 1, 0, -1};

        //create visited array so do not come on same point
        vector<vector<int>> vis(n,vector<int>(m,0));

        //traverse horizonatally only first and last row
        //check where got O 
        //if got O then apply dfs on i,j

        for(int i=0;i<m;i++){
            if(grid[0][i] == 'O'){
                dfs(0,i,grid,vis,delrow,delcol);
            }

            if(grid[n-1][i] == 'O'){
                dfs(n-1,i,grid,vis,delrow,delcol);
            }
        }

        //traverse first and last row vertically
         for(int i=0;i<n;i++){
            if(grid[i][0] == 'O'){
                dfs(i,0,grid,vis,delrow,delcol);
            }

            if(grid[i][m-1] == 'O'){
                dfs(i,m-1,grid,vis,delrow,delcol);
            }
        }
        

        //check if any 'O' which is not visited count convert that 'O' to 'X'
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='O' && !vis[i][j]){
                    grid[i][j] = 'X';
                }
            }
        }


    }
};
