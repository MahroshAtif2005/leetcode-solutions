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

        for(auto& neighbor : graph[course]){
            if(dfs(graph,state,neighbor)==false){
                return false;
            }
        }
        //finish the course cycle
        state[course] = 2;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       //lets make graph first
       vector<vector<int>> graph(numCourses);

       for(int i = 0; i<prerequisites.size(); i++){
          int course = prerequisites[i][0];
          int prerequisite = prerequisites[i][1];
          graph[course].push_back(prerequisite);
       }

       vector<int> state(numCourses,0);

       for (int course = 0; course<numCourses; course++){
         if(dfs(graph,state,course)==false){
           return false;
         }
       } 
      return true;
    }
};