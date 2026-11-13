class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        //set -> put elements of vector 1
        //if same elements appear in vector 2 add in answer vector
        unordered_map<int,int> map;

        for(int num : nums1){
            map[num]++;
        }

        vector<int> ans;

        for(int num: nums2){
            if(map.count(num) && map[num]>0){
                ans.push_back(num);
                map[num]--;
            }
        }

        return ans;
    }
};