class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    //space complexity o(n)
    //time compexity o(n log n) -> coz of the sorting
     unordered_map<int,int> map;
     for (int i = 0 ; i<nums.size(); i++){
        map[nums[i]]++;
     }
     vector<pair<int,int>> arr;
     for (const auto& entry : map){
        arr.push_back({entry.second,entry.first});
     }

     sort(arr.rbegin(),arr.rend());
     vector<int> ans;
     for (int i = 0; i<k ; i++){
       ans.push_back(arr[i].second);
     }
     return ans;
    }
};