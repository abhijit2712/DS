vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
          priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
          vector<int> dist(V,INT_MAX);
          
          dist[S] = 0;
          pq.push({0,S});
          
          while(!pq.empty()){
              int dis = pq.top().first;
              int node = pq.top().second;
              pq.pop();
              
              for(auto it : adj[node]){
                  int v = it[0];
                  int w = it[1];
                  
                  if(dis + w < dist[v]){
                        dist[v] = dis + w;
                        pq.push({dis + w,v});
                  }
                  
              }
          }
          
          return dist;
    }
