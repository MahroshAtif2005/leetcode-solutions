class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
         priority_queue<pair<int,int>> pq;
         long long distance = 0;
        
         for(int i = 0; i < points.size(); i++){
  distance = (points[i][0])*(points[i][0]) + (points[i][1])*(points[i][1]);
         pq.push({distance,i});
          while(pq.size()>k){
             pq.pop();
          }
         }
         vector<vector<int>> answer;
          while(!pq.empty()){
            int index = pq.top().second;
            answer.push_back(points[index]);
            pq.pop();
          }
          return answer;
    }
};