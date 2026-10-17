class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
      //find the comps which are not connected to each other, and comps -1 is the wires we need to connect em 
      if(connections.size()<n-1){
        return -1;
      }
      vector<vector<int>> adj(n);
      for(int i = 0; i<connections.size(); i++){
        int u = connections[i][0];
        int v = connections[i][1];

        adj[u].push_back(v);
        adj[v].push_back((u));
      }

      int components = 0;
      vector<bool> visited(n,false); //index no of computers
      for(int i = 0; i<n; i++){
          if(!visited[i]){
            components++;
            dfs(i,adj,visited);
          }
      }
      return components -1;
    }
    void dfs (int node, vector<vector<int>>& adj, vector<bool>& visited){
        visited[node]=true;
        for(int neighbour : adj[node]){
           if(!visited[neighbour]){
            dfs(neighbour,adj,visited);
           }
        }
    }
};