class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
     //use the priority queue and put all elements in and then return the top most 
     priority_queue<int> pq;

     for (int i = 0; i<nums.size(); i++){
        pq.push(nums[i]);
     }
    
     for (int i = 0; i < k-1; i++){
        pq.pop();
     }

     return pq.top();
    }
};