class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
      //go through the array 
      //store the content as key and and the root dir as value
      //if content matches add the root+filename as value  -> string||vector string hashmap
      //after root before file name there should be a '/' when i concatinate them
      //have a answer string and output the answer from the hashmap,
      //each part of the vector containing all the pairs where values are more than 1
      //map.second.size() > 1 that means duplicate and ad in ans vector 
      unordered_map<string,vector<string>> map;
      for (int i = 0; i<paths.size(); i++){

        int space = paths[i].find(' ');
        string rootDir = paths[i].substr(0,space);

        string remaining = paths[i].substr(space+1);

        while(remaining.find('(')!=string::npos){
        int pos1 = remaining.find('(');
        int pos2 = remaining.find(')');
        string content = remaining.substr(pos1+1,pos2 - pos1 - 1);

        string fileName = remaining.substr(0,pos1);
        
        map[content].push_back(rootDir+"/"+fileName);

        if (pos2 + 1 < remaining.size()) {
         remaining = remaining.substr(pos2 + 2);
         } else {
           remaining = "";
           }
        }
      }
     
     vector<vector<string>> answer;
     for(auto& entry: map){
        if(entry.second.size()>1){
         answer.push_back(entry.second);
        }
     }
     
     return answer;
    }
};