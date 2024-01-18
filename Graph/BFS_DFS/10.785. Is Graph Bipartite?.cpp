class Solution {
public:
    bool dfs(int node,int color,vector<vector<int>>& graph,vector<int> &colors){
        colors[node] = color;

        for(auto it : graph[node]){
            if(colors[it] == -1){
                if(dfs(it,!color,graph,colors) == false) return false;
            }else if(colors[it] == color) return false;
        }

        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        //consider all colors of node are -1 initially
        vector<int> colors(n+1,-1);

        for(int i=0;i<n;i++){
            if(colors[i] == -1){
                if(dfs(i,0,graph,colors) == false) return false;
            }
        }

        return true;
    }
};
