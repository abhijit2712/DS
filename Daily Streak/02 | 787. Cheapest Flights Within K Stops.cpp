class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //taking adjacy as a source node to distance
        vector<pair<int,int>> adj[n];

        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }  
        
        //steps, distance , node
        set<pair<int,pair<int,int>>> st;

        vector<int> dist(n,1e9);
        
        st.insert({0,{0,src}});
        dist[src] = 0;
        
        while(!st.empty()){
            auto top = *(st.begin()); 
            int steps = top.first;
            int distance = top.second.first;
            int node = top.second.second;
            st.erase(top);
            
            //if steps are greater than of k+1 continue the loop
            if(steps > k+1) continue;

            for(auto it : adj[node]){
                int newnode = it.first;
                int newDist = it.second;
                
                if(distance + newDist < dist[newnode] && steps<=k){
                   // if(dist[node] != INT_MAX) st.erase({dist[node],node}); 
                    
                    dist[newnode] = distance + newDist;
                    st.insert({steps+1,{dist[newnode],newnode}});
                }
            }
           
        }
        
        if(dist[dst] == 1e9) return -1;
        
        return dist[dst];
    }
};
