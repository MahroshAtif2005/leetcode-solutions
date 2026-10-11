class Solution {
public:

   bool dfs(vector<vector<int>>& graph, vector<int>& state, int course){
    if(state[course]==1){
        return false;
    }
    if(state[course]==2){
        return true;
    }
    state[course] = 1;
    for(int neighbour : graph[course]){
        if(!dfs(graph,state,neighbour)){
            return false;
        }
    }
    state[course]=2;
    return true;
   }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    //it is a cyclic graph
    //lets create a adj list so we can work with it and use dfs
    vector<vector<int>> graph(numCourses);
    
    for(int i = 0; i<prerequisites.size();i++){
      int course = prerequisites[i][0];
      int prerequisite = prerequisites[i][1];

      graph[prerequisite].push_back(course);
    }
    //now run a dfs to check if its a cycle
    vector<int> state(numCourses,0);
    for (int course = 0; course<numCourses; course++){
        if(dfs(graph,state,course)==false){
            return false;
        }
    }
    return true;
    }
};