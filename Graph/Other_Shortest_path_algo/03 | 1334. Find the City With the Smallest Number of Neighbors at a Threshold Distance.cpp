class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>> adj(n,vector<int>(n,1e9));
        //1.create the adj list
        for (auto it : edges) {
			adj[it[0]][it[1]] = it[2];
			adj[it[1]][it[0]] = it[2];
		}

        //mark 0 and infinity on particular cases
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adj[i][j] == -1) adj[i][j] = 1e9;
                if(i == j) adj[i][j] = 0;
            }
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    adj[i][j] = min(adj[i][j] , adj[i][k] + adj[k][j]);
                }
            }
        }

        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	               if(adj[i][j] == 1e9){
	                   adj[i][j] = -1;
	               }
	           }
	    }

        int cntCity = n;
		int cityNo = -1;
		for (int city = 0; city < n; city++) {
			int cnt = 0;
			for (int adjCity = 0; adjCity < n; adjCity++) {
				if (adj[city][adjCity] <= distanceThreshold)
					cnt++;
			}

			if (cnt <= cntCity) {
				cntCity = cnt;
				cityNo = city;
			}
		}
		return cityNo;
    }
};
