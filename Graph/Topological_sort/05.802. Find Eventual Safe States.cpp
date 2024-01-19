class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //1.create rev adjacency list
        int n = graph.size();
        vector<int> adj[n];

        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[graph[i][j]].push_back(i);
            }
        }

        //2.apply topo sort on this
        //2.find indegree of each node
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<adj[i].size();j++){
                indegree[adj[i][j]]++;
            }
        }

        //3.find indegree 0 node
        queue<int> q;
        //find number whose indegree is zero
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        //4.apply the bfs or khans algo
        vector<int> topo_order;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo_order.push_back(node);

            for(auto it : adj[node]){
                indegree[it]--;
        //5.if any node with 0 degree add that into queue 
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        } 

        //6,check condition if all elements are added if not there must be a cycle in a graph rreturn the empty array
      //  if(topo_order.size() != n) return {};

        //7.reverse the topological order to get a answer
        sort(topo_order.begin(), topo_order.end());
        return topo_order;
    }
};
