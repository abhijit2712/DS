class DisjointSet{
    public:
    vector<int> parent,rank,size;
    
    //constructor of class
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1);

        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    //find parent method -> this method uses the 
    //backtraking approach

    int findUPar(int node){
        //if got the ultimate parent node
        //then and only then return 
        if(node == parent[node]) return node;


        //if dont get any node got ultimate 
        //parent then find parent node
        //until don't find the ultimate parent node
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u,int v){
        //u and v are two node to attach each other
        

        //find the ultimate parent for both the node which you want to connect
        int up_of_u = findUPar(u);
        int up_of_v = findUPar(v);


        //if both have same parent then no need to connect them again
        if(up_of_u == up_of_v) return;


        //if rank of u is less then assing parent of v to u
        if(rank[up_of_u] < rank[up_of_v]){
            parent[up_of_u] = up_of_v;
        }
        else if(rank[up_of_v] <= rank[up_of_v]){
            //if if rank of v is less then assing parent of u to v
            parent[up_of_v] = up_of_u; 
        }else{
            parent[up_of_v] = up_of_u;
			rank[up_of_u]++;
        }
    }

    void unionBySize(int u,int v){
         //u and v are two node to attach each other
        

        //find the ultimate parent for both the node which you want to connect
        int up_of_u = findUPar(u);
        int up_of_v = findUPar(v);

        //if same 
        if(up_of_u == up_of_v) return;

        if(size[up_of_u] < size[up_of_v]){
            parent[up_of_u] = up_of_v;
            size[up_of_v] += size[up_of_u];
        }
        else{
            parent[up_of_v] = up_of_u;
            size[up_of_u] += size[up_of_v];
        }
        
    }
};

class Solution {
public:
    bool isValid(int row,int col,int n){
        return row>=0 && row<n && col>=0 && col<n;
    }


    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;

                int dr[] = {-1,0,1,0};
                int dc[] = {0,-1,0,1};

                for(int ind=0;ind<4;ind++){
                    int newr = i + dr[ind];
                    int newc = j + dc[ind];

                    if(isValid(newr,newc,n) && grid[newr][newc]==1){
                        int nodeNo = i*n + j;
                        int adjNodeNo = newr * n + newc;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }

        int mx = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1) continue;

                int dr[] = {-1,0,1,0};
                int dc[] = {0,-1,0,1};

                set<int> st;

                for(int ind=0;ind<4;ind++){
                    int newr = i + dr[ind];
                    int newc = j + dc[ind];

                    if(isValid(newr,newc,n) && grid[newr][newc]==1){
                        st.insert(ds.findUPar(newr*n+newc));
                    }


                    int size = 0;
                    for(auto it : st){
                        size += ds.size[it];
                    }

                    mx = max(mx, size+1);
                }
            }
        }

        for(int cellno=0;cellno<n*n;cellno++){
                mx = max(mx,ds.size[ds.findUPar(cellno)]);
        }


        return mx;
    }
};
