class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
     //build adgency list
     vector<vector<pair<int,int>>> adj(n+1);

     for(auto& edge : times){
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        adj[u].push_back({v,w}); //we are storing the neghingg nodes and the weights leading to it
     }

     //initialise out ditances array so we can keep track of the shortest distance yet from our starting position
     vector<int> dist(n+1,INT_MAX); //INT_MAX represents infinity, meaning we haven't found a path to that node yet.
     dist[k]=0; //because reaching the starting node costs nthg

     //now a priority queue to keep track of the smallest know distance till now
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
     pq.push({0,k});

     //now main dijkstras algorithm
     while(!pq.empty()){
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

         if (d > dist[node]) continue;

          // Explore neighbors
            for (auto& neighbor : adj[node]) {

                int nextNode = neighbor.first;
                int weight = neighbor.second;

                // Relaxation
                if (d + weight < dist[nextNode]) {
                    dist[nextNode] = d + weight;
                    pq.push({dist[nextNode], nextNode});
                }
            }
     }
            // Step 5: Find maximum shortest distance
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) {
                return -1;
            }

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};