class Solution {
public:
    string frequencySort(string s) {

        //use a hashmap and strore feq of each character
        unordered_map<char,int> map;
        for (int i =0;i<s.size();i++){
            map[s[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto element : map){
            pq.push({element.second,element.first});
        }
        string answer;
        while(!pq.empty()){
            int frequency = pq.top().first;
            char character = pq.top().second;
            for (int i= 0; i< frequency; i++){
                answer+= character;
            }
            pq.pop();
        }
        return answer;
    }
};