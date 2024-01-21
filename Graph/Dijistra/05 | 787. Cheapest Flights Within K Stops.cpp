class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        

        vector<pair<int,int>> adj[n];
        for(auto it : flights){
               adj[it[0]].push_back({it[1],it[2]});
        }  

        vector<int> dist(n,1e9);
        set<pair<int,pair<int,int>>> st;
        st.insert({0,{0,src}});
        dist[src] = 0;

        while(!st.empty()){
            auto top = *(st.begin()); 
            int distance = top.second.first;
            int node = top.second.second;
            int steps = top.first;
            st.erase(top);

            if(steps > k+1) continue;

            for(auto it : adj[node]){
                int newNode = it.first;
                int newDistance = it.second;

                if(newDistance + distance < dist[newNode] && steps<=k){
                    dist[newNode] = newDistance + distance;
                    st.insert({steps+1,{dist[newNode],newNode}});
                }
            }
        } 

        if(dist[dst] == 1e9) return -1;

        return dist[dst];
    }
};
