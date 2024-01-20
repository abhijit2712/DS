  vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        set<pair<int,int>> st;
        vector<int> dist(V,INT_MAX);
        
        st.insert({0,S});
        dist[S] = 0;
        
        while(!st.empty()){
            auto stTop = *(st.begin()); 
            int distance = stTop.first;
            int rootNode = stTop.second;
            st.erase(stTop);

            for(auto it : adj[rootNode]){
                int node = it[0];
                auto newDist = it[1];
                
            
                if(distance + newDist < dist[node]){
                    if(dist[node] != INT_MAX) st.erase({dist[node],node}); 
                    
                    dist[node] = distance + newDist;
                    st.insert({dist[node],node});
                }
            }
        }
        
        
        return dist;
