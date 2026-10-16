class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> set;
        vector<string> answer;

        for (auto& f : folder) {
            set.insert(f);
        }

        for (int i = 0; i<folder.size(); i++){

        string file = "";
        bool isSubfolder = false;

          for (int j = 0; j < folder[i].size(); j++) {
            if (folder[i][j] == '/' && j != 0) {
                if(set.count(file)){
                    isSubfolder = true;
                    break;
                }
             }
            file += folder[i][j];
        }
        if(!isSubfolder){
         answer.push_back(folder[i]);
        }
      }
      return answer;
    }
};