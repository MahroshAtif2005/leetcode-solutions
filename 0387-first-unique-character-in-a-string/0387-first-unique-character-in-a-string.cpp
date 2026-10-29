class Solution {
public:
    int firstUniqChar(string s) {
        //put  chars in a hashset
        //go through the string, if not in hashset return index
       unordered_map<char,int> map;
       for(char c: s){
        map[c]++;
       }
        for(int i=0; i<s.size(); i++){
            if(map[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};