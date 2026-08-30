class Solution {
public:
    int search(vector<int>& nums, int target) {
        //solve the array by binary search
        //since its rotated, sort the array first
        int left = 0;
        int right = nums.size()-1;

        while(left<=right){
          int mid = left + (right - left) / 2;
          if(target==nums[mid]){
            return mid;
          }

          // LEFT is sorted
          if(nums[left]<=nums[mid]){
            //target lies in the left half
            if(nums[left]<=target && target<nums[mid]){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
          }
        else{
          // RIGHT is sorted
          if(nums[mid]<target && target<=nums[right]){
            // if target lies in right half
              left = mid+1;
            }else{
                right = mid -1;
            } 
           }
        }
        return -1;
    }
};