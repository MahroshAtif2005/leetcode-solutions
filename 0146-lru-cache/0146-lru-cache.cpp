class LRUCache {
public:
int maxCapacity;
list<pair<int,int>> dll; //doubly linked list
unordered_map<int, list<pair<int,int>>::iterator> map;
    LRUCache(int capacity) {
        maxCapacity = capacity;
    }
    
    int get(int key) {
        if(!map.count(key)){
            return -1;
        }

        dll.splice(dll.begin(),dll,map[key]);

        return map[key]->second;
    }
    
    void put(int key, int value) {
        if(map.count(key)){
            map[key]->second = value;
            dll.splice(dll.begin(),dll,map[key]);
            return;
        }
        if(int(dll.size())==maxCapacity){
            map.erase(dll.back().first);
            dll.pop_back();
        }
        dll.push_front({key,value});
        map[key]=dll.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */