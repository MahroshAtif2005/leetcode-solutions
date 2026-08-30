class Solution {
public:
    int findMin(vector<int>& nums) {
       /* sort(nums.begin(),nums.end());
        return nums[0];
        */
        // we can't sort array coz it takes -> O(n log n) time
        // but the question asks to use O(log n) time which means Binary Search
        int left = 0;
        int right = nums.size()-1;
        while (left<right){
            int mid = left + (right-left)/2;

            if (nums[mid]>nums[right]){
                left = mid+1;
            }
            else{
                right = mid;
            }
        }
        return nums[left];
    }
};