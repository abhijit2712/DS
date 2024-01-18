class Solution {
public:   
    int n;
    int m;

    void dfs(vector<vector<int>>& image,int initcolor,int finalcolor,int row,int col){
        image[row][col] = finalcolor;
        int rows[] = {-1,0,1,0};
        int cols[] = {0,1,0,-1};

        for(int i=0;i<4;i++){
            int nrow = row + rows[i];     //adjacent row
            int ncol = col + cols[i];     //adjacent col

        //Checking whether it is out of bound or not & also checking that adjacent   
        //row col is equal to initial color && also check it is not equal to new color
 
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==initcolor && image[nrow][ncol]!=finalcolor){
            dfs(image,initcolor,finalcolor,nrow,ncol);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size();
        m = image[0].size();
        int initcolor = image[sr][sc];

        dfs(image,initcolor,color,sr,sc);
        return image;
    }
};
