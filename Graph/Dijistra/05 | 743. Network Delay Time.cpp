class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(int i=0;i<times.size();i++)
        {
            adj[times[i][0]].push_back(make_pair(times[i][1],times[i][2]));//node,weight
            
        }

        vector<int> dist(n+1,1e9);
        set<pair<int,int>> st;
        st.insert({0,k});
        dist[k] = 0;

        while(!st.empty()){
            auto top = (*st.begin());
            int distance = top.first;
            int node = top.second;
            st.erase(st.begin());

            for(auto it : adj[node]){
                int newDist = it.second;
                int newNode = it.first;

                if(newDist + distance < dist[newNode]){
                  //  if(dist[node] != 1e9) st.erase({dist[newNode],newNode});

                    dist[newNode] = newDist + distance;
                    st.insert({dist[newNode],newNode});
                }
            }
        }

        int mx = *max_element(begin(dist) + 1, end(dist));
        return  mx == 1e9 ? -1 : mx;
    }
};
