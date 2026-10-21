class Solution {
public:
    bool dfs( vector<vector<int>>& graph, vector<int>& state, int course,vector<int>& answer){
        if (state[course]==1){
            return false;
        }
        if(state[course]==2){
            return true;
        }

        state[course]=1;

        for (auto& neighbor : graph[course]){
          if(dfs(graph,state,neighbor,answer)==false){
                return false;
            }
        }
        state[course] = 2;
        answer.push_back(course);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(int i = 0; i<prerequisites.size(); i++){
            int course = prerequisites[i][0];
            int prerequite = prerequisites[i][1];

            graph[course].push_back(prerequite);
        }

        vector<int> state(numCourses,0);
        vector<int> answer;

        for (int course = 0; course<numCourses; course++){
            if(dfs(graph,state,course,answer)==false){
                return {};
            }
        }
        return answer;
    }
};