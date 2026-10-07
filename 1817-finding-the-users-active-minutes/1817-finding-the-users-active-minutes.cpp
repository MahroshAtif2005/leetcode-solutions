class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        //the map will be representing user id and unique active minutes
        unordered_map<int,unordered_set<int>> map; // keeping time and user id
        for(int i = 0; i<logs.size(); i++){
            map[logs[i][0]].insert(logs[i][1]);
        }
        vector<int> answer(k,0);
        for (auto user : map){
            int uam = user.second.size();
            answer[uam-1]++;
        }
        return answer;
    }
};