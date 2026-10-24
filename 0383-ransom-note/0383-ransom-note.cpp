class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        //put magazines chars in hashmap with their count
        //go though ransom, whne u see a char and its in a map , decrement in the map
        //if not in the map return false
        //if it reaches end return true
        unordered_map<char,int> freq;

        for(char c: magazine){
            freq[c]++;
        }

        for(char c: ransomNote){
            if(!freq[c]){
                return false;
            }
            freq[c]--;
            if(freq[c]==0){
                freq.erase(c);
            }
        }
        return true;
    }
};