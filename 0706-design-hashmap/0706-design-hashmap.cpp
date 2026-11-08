class MyHashMap {
public:
  int size;
  int count;
  vector<vector<pair<int,int>>> buckets;
  //In a real implementation I’d track the load factor (items ÷ buckets) and resize and rehash into double the buckets when it passes about 0.75, which keeps operations O(1) on average

  //Negative keys. In C++, -7 % 10 is -7, which would give an invalid index. LeetCode 706 only uses non-negative keys, but in an interview, mention it and handle it: ((key % size) + size) % size.
  
    MyHashMap() {
        size = 10;
        count = 0;
        buckets.resize(size);
    }

    void rehash(){
        int newSize = size*2;
        vector<vector<pair<int,int>>> newBuckets(newSize);
        //when the number of buckets changes, the bucket index might change too
        for(auto& bucket: buckets){
            for(auto& p: bucket){
                int newIndex = p.first % newSize;
                newBuckets[newIndex].push_back(p);
            }
        }
        buckets = move(newBuckets);
        size = newSize;
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