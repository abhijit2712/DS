ector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        vector<vector<int>> adj(V);
        
        for(int i = 0; i < edges.size(); i++){
            int u, v;
            u = edges[i].first;
            v = edges[i].second;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
  
        return adj;
    }
