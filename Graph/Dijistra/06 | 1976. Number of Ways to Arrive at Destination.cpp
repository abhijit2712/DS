#define ll long long
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<pair<int,int>> adj[n];

        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<ll> ways(n,0);
        vector<ll> dist(n,1e15);
        set<pair<ll,ll>> st;
        st.insert({0,0});
        dist[0] = 0;
        ways[0] = 1;

        ll mod = 1e9 + 7;

        while(!st.empty()){
            auto top = *(st.begin()); 
            ll dis  = top.first;
            ll node = top.second;
            st.erase(top);

            for(auto it : adj[node]){
                ll newNode = it.first;
                ll newDist = it.second;

                if(newDist + dis < dist[newNode]){
                    dist[newNode] = newDist + dis;
                    st.insert({dis+newDist,newNode});
                    ways[newNode] = ways[node];
                }
                else if(newDist + dis == dist[newNode]){
                    ways[newNode] = (ways[node] + ways[newNode]) % mod;
                }
            }
        }

        ll num = ways[n-1] %mod;
        if(num == 0) return 1;
        return num;
    }
};
