class Solution {
public:
    struct Compare{
        bool operator()(pair<string,int>& a, pair<string,int>& b){
            if(a.second != b.second){
          return a.second > b.second;
            }
           return a.first<b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
    //store word in hashmap and and its freq
    unordered_map<string,int> freq;

    for (int i = 0; i<words.size(); i++){
        freq[words[i]]++;
    }

    //now sort, i can use custom sort to sort and return top k but that will take o n log n time
    //so what if i use priority queue but will custom sort work in pq? i think it should
    
    priority_queue<pair<string,int>, vector<pair<string,int>>,Compare> minHeap;
   
   for(auto& entry: freq){
     minHeap.push(entry);
     if(minHeap.size()>k){
        minHeap.pop();
     }
   }

   vector<string> answer; 
   for (int i = 0; i<k; i++){
    string value = minHeap.top().first;
    minHeap.pop();
    answer.push_back(value);
   }

   reverse(answer.begin(), answer.end());
    
    return answer;
    }

};