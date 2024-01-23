class DisjointSet{
    public:
    vector<int> parent,rank,size;
    
    //constructor of class
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1);

        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    //find parent method -> this method uses the 
    //backtraking approach

    int findUPar(int node){
        //if got the ultimate parent node
        //then and only then return 
        if(node == parent[node]) return node;


        //if dont get any node got ultimate 
        //parent then find parent node
        //until don't find the ultimate parent node
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u,int v){
        //u and v are two node to attach each other
        

        //find the ultimate parent for both the node which you want to connect
        int up_of_u = findUPar(u);
        int up_of_v = findUPar(v);


        //if both have same parent then no need to connect them again
        if(up_of_u == up_of_v) return;


        //if rank of u is less then assing parent of v to u
        if(rank[up_of_u] < rank[up_of_v]){
            parent[up_of_u] = up_of_v;
        }
        else if(rank[up_of_v] <= rank[up_of_v]){
            //if if rank of v is less then assing parent of u to v
            parent[up_of_v] = up_of_u; 
        }else{
            parent[up_of_v] = up_of_u;
			rank[up_of_u]++;
        }
    }

    void unionBySize(int u,int v){
         //u and v are two node to attach each other
        

        //find the ultimate parent for both the node which you want to connect
        int up_of_u = findUPar(u);
        int up_of_v = findUPar(v);

        //if same 
        if(up_of_u == up_of_v) return;

        if(size[up_of_u] < size[up_of_v]){
            parent[up_of_u] = up_of_v;
            size[up_of_v] += size[up_of_u];
        }
        else{
            parent[up_of_v] = up_of_u;
            size[up_of_u] += size[up_of_v];
        }
        
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& details) {
         int n = details.size();
        DisjointSet ds(n);
        sort(details.begin(), details.end());
        unordered_map<string, int> mapMailNode;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < details[i].size(); j++) {
                string mail = details[i][j];
                if (mapMailNode.find(mail) == mapMailNode.end()) {
                    mapMailNode[mail] = i;
                }
                else {
                    ds.unionBySize(i, mapMailNode[mail]);
                }
            }
        }

        vector<string> mergedMail[n];
        for (auto it : mapMailNode) {
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {
            if (mergedMail[i].size() == 0) continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(details[i][0]);
            for (auto it : mergedMail[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
