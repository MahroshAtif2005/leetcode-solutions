class RandomizedSet {
public:
 vector<int> nums;
 unordered_map<int,int> map;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(map.count(val)){
          return false;
        }
        nums.push_back(val);
        map[val] = nums.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(!map.count(val)){
            return false;
        }
        int index = map[val];
        int lastVal = nums.back();

        nums[index] = lastVal;
        map[lastVal] = index;

        nums.pop_back();
        map.erase(val);

        return true; 
    }
    
    int getRandom() {
        //int index = rand() % nums.size(); generates a random valid index for the vector. rand() generates a random integer, while % nums.size() takes the remainder when dividing that integer by the vector's size. This ensures the index is between 0 and nums.size() - 1
       int index = rand() % nums.size();
       return nums[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */