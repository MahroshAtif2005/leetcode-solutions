class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

      vector<pair<int,int>> cars;
      for (int i = 0;i<position.size();i++){
        cars.push_back({position[i],speed[i]});
      }
      //sort in decreasing order
      sort(cars.rbegin(),cars.rend());
      
      int fleets = 0;
      double slowestTime = 0;
      for(auto car: cars){
        double time = (double) (target-car.first)/car.second;

        if(time>slowestTime){
            fleets++;
            slowestTime = time;
        }
      }
      return fleets;
    }
};