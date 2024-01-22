class DisjointSet{
public:
vector<int> rank,parent,size;

	DisjointSet(int n){
		rank.resize(n+1, 0);
		parent.resize(n+1);
		size.resize(n+1);

		for(int i=0; i<=n; i++){
		 size[i]  = 1;
		 parent[i] = i;
		}
	}

	int findUPar(int node){
		if(node == parent[node]) return node;

		return parent[node] = findUPar(parent[node]);
	}

	void unionByRank(int u, int v){
		int ulp_u = findUPar(u);
		int ulp_v = findUPar(v);

		if(ulp_u == ulp_v) return;

		if(rank[ulp_u] <= rank[ulp_v]){
			parent[ulp_u] = ulp_v;
		}
		else if(rank[ulp_u] > rank[ulp_v]){
			parent[ulp_v] = ulp_u;
		}
		else{
			parent[ulp_v] = ulp_u;
			rank[ulp_u]++;
		}
 	}


 	void unionBySize(int u,int v){
 		int ulp_u = findUPar(u);
		int ulp_v = findUPar(v);

		if(ulp_u == ulp_v) return;

		if(size[ulp_u] < size[ulp_v]){
			parent[ulp_u] = ulp_v;
			size[ulp_v] += size[ulp_u];
		}
		else{
			parent[ulp_v] = ulp_u;
			size[ulp_u]  += size[ulp_v];
		}
 	}
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>> edges;
        
        
        for(int i=0;i<V;i++){
            for(auto it : adj[i]){
                int node = i;
                int adjcentnode = it[0];
                int wt = it[1];
                 edges.push_back({wt, {node,adjcentnode}});
            }
        }
        
        sort(edges.begin(),edges.end());
        
        DisjointSet ds(V+1);
        int sum = 0;
        
        for(auto it : edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
             if (ds.findUPar(u) != ds.findUPar(v)) {
                sum += wt;
                ds.unionBySize(u, v);
            }
            
        }
        
        return sum;
    }
};
