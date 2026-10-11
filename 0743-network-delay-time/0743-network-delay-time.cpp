class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int,int>>> adj(n+1);
     //adj list
     for(auto& entry : times){
       int u = entry[0];
       int v = entry[1];
       int w = entry[2];

       adj[u].push_back({v,w});
     } 
   //index storing the node num
   //shortest distance discovered so far from the STARTING node (k) to each node.
  vector<int> dist(n+1,INT_MAX);
  dist[k] = 0;
  
  //Min priority queue: stores {distance, node}
  //Processes the node with the smallest known distance first

  priority_queue<pair<int,int>,vector<pair<int,int>>,
  greater<pair<int,int>>> pq;
  pq.push({0,k});

  while(!pq.empty()){
    int d = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if(d>dist[node]) continue;

    for (auto& neighbour : adj[node]){
       int nextNode = neighbour.first;
       int weight = neighbour.second;

       if(d+weight<dist[nextNode]){
         dist[nextNode] = d+weight;
         pq.push({dist[nextNode],nextNode});
       }
    }
  }
  int ans = 0;
  for (int i = 1; i <dist.size(); i++){
    if (dist[i]==INT_MAX){
      return -1;
    }
    ans = max(ans,dist[i]);
  }
  return ans;
       
     }
};