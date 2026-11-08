class MyHashMap {
public:
  int size;
  vector<vector<pair<int,int>>> buckets;
    MyHashMap() {
        size = 10;
        buckets.resize(size);
    }
    
    void put(int key, int value) {
       int index = key % size;
       for(auto& p : buckets[index]){
         if(p.first==key){
            p.second = value;
            return;
         }
       }
       buckets[index].push_back({key,value});
    }
    
    int get(int key) {
       int index = key % size;
       for(auto& p : buckets[index]){
        if(p.first==key){
            return p.second;
        }
       }
       return -1;
    }
    
    void remove(int key) {
       int index = key % size;
       for(int i = 0; i<buckets[index].size(); i++){
        if(buckets[index][i].first==key){
            buckets[index].erase(buckets[index].begin()+i);
            return;
        }
       }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */