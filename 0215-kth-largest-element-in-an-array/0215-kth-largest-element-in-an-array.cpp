class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
     //min heap
     priority_queue<int,vector<int>,greater<int>> pq; // we cant initialese a pq here of size k (not possible)
     for (int i = 0; i<nums.size(); i++){
        pq.push(nums[i]);

        if(pq.size()>k){
               pq.pop();     
        }
     }

     return pq.top();
    }
};