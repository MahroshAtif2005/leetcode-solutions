class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> map;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto it = map.find(key);

        if(it==map.end()){
            return "";
        }

        int left = 0;
        int right = it->second.size()-1;
        string answer;

        while(left<=right){
            int mid = left + (right-left) /2;

            if(it->second[mid].first<=timestamp){
                answer = it->second[mid].second;
                left = mid + 1;
            }else{
                right = mid - 1;
            }

        }

        return answer;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */