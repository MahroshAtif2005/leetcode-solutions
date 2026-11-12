class RandomizedSet {
public:
 vector<int> random;
 unordered_map<int,int> map;
    RandomizedSet() {   
    }
    
    bool insert(int val) {
        if(!map.count(val)){
            random.push_back(val);
            map[val] = random.size()-1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(!map.count(val)){
            return false;
        }
        int index = map[val];
        int lastVal = random.back();
        
        random[index]=lastVal;
        map[lastVal] = index;

        random.pop_back(); 
        map.erase(val);
        return true;
    }
    
    int getRandom() {
        int num = rand() % random.size();//we get the randome index not actual value
        return random[num];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */