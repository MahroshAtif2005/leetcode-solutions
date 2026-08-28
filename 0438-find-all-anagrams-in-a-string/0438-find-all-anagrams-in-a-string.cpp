class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> freq1;
        unordered_map<char,int> freq2;
        vector<int> indices;
       int left = 0;
       for(char c : p){
        freq1[c]++;
       }

       for(int right = 0; right<s.size();right++){
         freq2[s[right]]++;
         if((right-left+1)>p.size()){
            freq2[s[left]]--;
            if(freq2[s[left]]==0){
                freq2.erase(s[left]);
            }
            left++;
         }
         if(freq1==freq2){
                indices.push_back(left);
            }
       }
       return indices;
    }

};