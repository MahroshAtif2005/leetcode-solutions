class StockPrice {
public:
    //a hashmap storing the records timestamp and its price
   unordered_map<int, int> map;
   multiset<int> prices; //stores all current prices in sorted order, so we can quickly find the minimum and maximum
   int latest = 0;

    StockPrice() {
    }
    
    void update(int timestamp, int price) {

          // If timestamp exists, remove its old price
        if (map.count(timestamp)) {
            prices.erase(prices.find(map[timestamp]));
        }

        map[timestamp] = price;
        prices.insert(price);

         // Track the largest timestamp
        latest = max(latest, timestamp);
    }
    
    int current() {
      return map[latest];
    }
    
    int maximum() {
       int max = *prices.rbegin();
       return max;
    }
    
    int minimum() {
        int min = *prices.begin();
        return min; 
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */