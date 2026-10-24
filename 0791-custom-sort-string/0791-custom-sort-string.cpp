class Solution {
public:
    string customSortString(string order, string s) {
        //put all the elements of the string s in the hash map n its freq
        //go through the array order each char
        //if the char in order is in the hashmap
        //concatinate to the answer string and decrement from map
        //
        //then to concatinate the rest of the elements fo though the s string again if any of its element is still in hashmap concatinate with asnwer
        
        unordered_map<char,int> map;
        for(char c: s){
            map[c]++;
        }
        string answer;
        for(char c: order){
            if(map.count(c)){
              while(map[c]>0){
                answer+=c;
                map[c]--;
              }
            }
        }

        for(char c: s){
            if(map.count(c)){
                while(map[c]>0){
                    answer+=c;
                    map[c]--;
                }
            }
        }

        return answer;
    }
};