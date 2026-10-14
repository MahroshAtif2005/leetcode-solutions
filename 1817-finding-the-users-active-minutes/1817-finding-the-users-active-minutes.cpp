class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
     //number of users whos uam equals j so array index represent time
     //in hashmap store the id as key and then the unique minutes he perfomed work
     //we can count the uniqueue minutes size to get our uam at time t
     //in the answer array then we can store array[map.second.size()-1]++
     unordered_map<int,unordered_set<int>> map;
     for (int i = 0; i<logs.size(); i++){
        map[logs[i][0]].insert(logs[i][1]);
     }
     vector<int> answer(k);
     for(auto& entry: map){
       answer[entry.second.size()-1]++;
     }
     return answer;
    }
};