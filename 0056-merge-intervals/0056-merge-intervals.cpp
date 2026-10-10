class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        if (intervals.empty()) return {};
        
        for (int i = 1; i<intervals.size(); i++){
            vector<int>& lastMerged = merged.back();
            if(lastMerged[1]>=intervals[i][0]){
               lastMerged[1] = max(lastMerged[1], intervals[i][1]);
            }else{
              merged.push_back(intervals[i]);
            }
        }
        return merged;
    }
};