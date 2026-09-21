class Solution {
public:
    string frequencySort(string s) {

        //use a hashmap and strore feq of each character
        unordered_map<char,int> map;
        for (int i =0;i<s.size();i++){
            map[s[i]]++;
        }

        //create a pair array and store hashmap elements on it
        vector<pair<int,char>> freq;

        //we put freq first and then the value 
        for (auto &pair : map){
           freq.push_back({pair.second,pair.first});
        }

        //sort in decending order
        sort(freq.rbegin(),freq.rend());

        //create a string which we will return
        string ans;

        for (int i = 0; i<freq.size();i++){
          for (int j = 0; j<freq[i].first;j++){
          ans+= freq[i].second;
          }
        }
        return ans;
        
    }
};