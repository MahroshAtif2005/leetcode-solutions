class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        
        //start with count == 1
        //if count 1 exists add 2 and so on
        //go though each word put the word in the word in map and and then its number as int how many times we saw it already

        unordered_map<string,int> map;
        vector<string> answer;

        for (int i = 0; i<names.size(); i++){       
            if(!map.count(names[i])){
                map[names[i]]++;
                  answer.push_back(names[i]);
            }else{
                int num = map[names[i]];
                string newName = names[i] + '(' + to_string(num) + ')';
                while(map.count(newName)){
                  num++;
                  newName = names[i] + '(' + to_string(num) + ')';
                }
                map[newName]++;
                map[names[i]] = num + 1;

                answer.push_back(newName);
            }
        }
        return answer;
    }
};