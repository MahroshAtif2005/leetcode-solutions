class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        //create a hashmap and store person id and timestamp
        unordered_map<string,vector<int>> map;

        for(int i = 0; i<keyName.size(); i++){
            //convert time to minutes
            int pos = keyTime[i].find(':');
            int minutes = stoi(keyTime[i].substr(pos+1));
            
            string timeStamp = keyTime[i].substr(0,pos);
            minutes += stoi(timeStamp) * 60;
            map[keyName[i]].push_back(minutes);
        }
    
        vector<string> answer;
        for(auto& element : map){
            if (element.second.size()>=3){
                sort(element.second.begin(),element.second.end());
                for(int i = 2; i< element.second.size();i++){
                    //we only need to compare first and 3rd in the group
                    if (element.second[i] - element.second[i-2] <= 60) {
                      answer.push_back(element.first);
                      break;
                       }
                }
                
            }
        }
        sort(answer.begin(),answer.end());
        return answer;
    }
};