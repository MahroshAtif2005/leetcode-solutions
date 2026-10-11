class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
     //adj list
     vector<vector<pair<int,int>>> adj(n+1);
     for (auto& edge: times){
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        adj[u].push_back({v,w});
     }

     vector<int> dist(n+1,INT_MAX);
     dist[k] = 0;

     //min heap storing
     priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

     pq.push({0,k});

     //dijkstras algorithm
     while(!pq.empty()){
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(d>dist[node]) continue;

        for (auto& neighbour: adj[node]){
            int nextNode = neighbour.first;
            int weight = neighbour.second;

            if(d+weight < dist[nextNode]){
                dist[nextNode] = d+weight;
                pq.push({dist[nextNode],nextNode});
            }
        }
     }
     int ans = 0;

     for (int i = 1; i<=n; i++){
        if (dist[i]==INT_MAX){
            return -1;
        }
        ans = max(ans,dist[i]);
     }
   return ans;
    }
};