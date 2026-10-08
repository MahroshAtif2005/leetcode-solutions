class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> checkIns; //to keep id and then station name and checkin time
    unordered_map<string,pair<int,int>> checkOuts;//route as key a->b and then total time and , no of travels
    UndergroundSystem() {
  
    }
    
    void checkIn(int id, string stationName, int t) {
        if(!checkIns.count(id)){
            checkIns[id] = {stationName,t};
        }
    }
    
    void checkOut(int id, string stationName, int t) {
        string startStation = checkIns[id].first;
        int startTime = checkIns[id].second;
        int travelTime = t - startTime;

        string route = startStation + "->" + stationName;
      
         checkOuts[route].first += travelTime;
         checkOuts[route].second++;

         checkIns.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
      string way = startStation + "->" + endStation;
      int time = checkOuts[way].first;
      int journeys = checkOuts[way].second;
      double averageTime = (double) time/journeys;
      return averageTime;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */