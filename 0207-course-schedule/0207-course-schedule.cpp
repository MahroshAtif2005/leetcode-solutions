class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& state, int course){
        // currenlty in our dfs path -> cycle
        if(state[course]==1){
            return false;
        }
        //already completed -> safe
        if(state[course]==2){
            return true;
        }
        //mark aas currently exploring
        state[course]=1;
        for (int neighbor : graph[course]){
              if (!dfs(graph, state, neighbor)) {
                return false;
            }
        }
        //finished exploring this course
        state[course]=2;

        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (int i = 0; i<prerequisites.size(); i++){
               int course = prerequisites[i][0];
               int prerequisite = prerequisites[i][1];

               graph[prerequisite].push_back(course);

               //now run a dfs to check if its a cycle
        }
        // 0 = not visited
        // 1 = currently exploring
        // 2 = completely finished
        vector<int> state(numCourses,0);
        for (int course = 0; course < numCourses; course++){
            if(dfs(graph,state,course)==false){
               return false;
            }
        }
        return true;
    }
};