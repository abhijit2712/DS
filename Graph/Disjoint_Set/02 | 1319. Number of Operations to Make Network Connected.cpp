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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n - 1 > connections.size()) return -1;

        //1.create adjacecy list
        vector<int> adj[n];
        DisjointSet ds(n);

        int cnt = 0;
        for(int i=0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];

            int parent_u = ds.findUPar(u);
            int parent_v = ds.findUPar(v);

            if(parent_u == parent_v){
                cnt++;
            }else{
                ds.unionBySize(u,v);
            }
        }

        set<int> st;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(ds.parent[i] == i) ans++;
        }
        
        return ans-1;
    }
};
