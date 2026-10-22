class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
    //represents unique minutes s
    // 1->0
    // 2->2
      vector<int> uam(k,0);
      unordered_map<int,unordered_set<int>> map;

      for(int i=0; i<logs.size(); i++){
        map[logs[i][0]].insert(logs[i][1]);
      }

      for(auto& entry: map){
        uam[entry.second.size()-1]++;
      }

      return uam;
    }
};