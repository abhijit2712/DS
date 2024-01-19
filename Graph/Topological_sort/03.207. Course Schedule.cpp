class Solution {
public:
    bool dfs(int node, int parent,vector<int> &vis, vector<int> adj[]) {

       //this condition detect the whether the cycle is present
        if(vis[node] == 1) return true;

        if(vis[node] == false){
        //mark the node as true
        vis[node] = true;
        // visit adjacent nodes 
        for(auto adjacentNode: adj[node]) {
            // unvisited adjacent node
            if(dfs(adjacentNode, node, vis, adj)) 
                    return true; 
            }
        }

        //if the node is already visited by another dfs call then
        // due to this node = 2 it will not execute above code so that 
        //it will not give tle ,this statement help to avoid tle
        vis[node] = 2;
        return false; 
    }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses == 1 || prerequisites.size()==0) return true;
    
        vector<int> adj[numCourses];

        //create adjacecy list
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back( prerequisites[i][1]);
        }

        //create a visited array for the traversal
        int cycleFlag=0;
        vector<int> vis(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                //if cyle found the mark cycle flag == 0
                if(dfs(i,-1,vis,adj)) cycleFlag = 1;
            }
        }

        if(cycleFlag==0) return true;
        return false;
    }
};
