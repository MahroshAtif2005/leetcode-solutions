class TimeMap {
public:
    unordered_map<string,vector<pair<string,int>>> map;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        int left = 0;
        int right = map[key].size()-1;
        string ans = "";
        int prevTimestamp = 0;
        string value = "";
        while(left<=right){
          int mid = left+(right-left)/2;
         if (map[key][mid].second <= timestamp) {
              value = map[key][mid].first;
              left = mid + 1;
          }else{
             right = mid - 1; 
          }
        }
        return value;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */