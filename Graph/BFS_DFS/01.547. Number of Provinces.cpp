class Solution {
public:
    void dfs(int node,vector<int> adj[],vector<int> &vis){
        vis[node] = 1;

        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }

    }


    int findCircleNum(vector<vector<int>>& arr) {
        int n = arr.size();
        
        vector<int> adj[n+1];

        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[i].size();j++){
                if(arr[i][j] == 1){
                    adj[i].push_back(j);
                }
            }
        }

        // for(int i=0;i<=n;i++){
        //     for(auto x : adj[i]) cout << x+1 << "  ";
        //     cout << endl;
        // }


        int cnt = 0;
        vector<int> vis(n+1,0);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                cnt++;
            }
        }

        return cnt;
    }
};
