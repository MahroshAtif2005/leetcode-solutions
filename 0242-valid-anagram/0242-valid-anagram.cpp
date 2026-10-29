class Solution {
public:
    bool isAnagram(string s, string t) {
        // create a hashmap : store the letter n its count for string s
        // if it matches for string t then the answer is true
        unordered_map<char,int> map;
        for(char c: s){
            map[c]++;
        }

        if(s.size()!=t.size()){
            return false;
        }

        for(int i = 0; i<t.size(); i++){
            if(!map.count(t[i])){
                return false;
            }else{
                map[t[i]]--;
                if(map[t[i]]==0){
                    map.erase(t[i]);
                }
            }
        }
        return true;
    }
};