class SnapshotArray {
public:
    vector<vector<pair<int,int>>> history;
    int snapId = 0;
    SnapshotArray(int length) {
        history.resize(length);
    }
    
    void set(int index, int val) {
        //we check back becuz last element contains most recent chnages to make to that index
        if(!history[index].empty() && history[index].back().first==snapId){
            history[index].back().second = val;
         }else{
            history[index].push_back({snapId,val});
         }
    }
    
    int snap() {
        snapId++;
        return snapId-1;
    }
    
    int get(int index, int snap_id) {
        int left = 0;
        int right = history[index].size()-1;
        int ans = 0;

        while(left<=right){
          int mid = left + (right-left)/2;
          if(history[index][mid].first<=snap_id){//diff snap id, its what user wants to retrieve not our counter!
            ans = history[index][mid].second;
            left = mid + 1;
          }else{
            right = mid - 1;
          }

        }
         return ans;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */