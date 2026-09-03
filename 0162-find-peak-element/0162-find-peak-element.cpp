class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //binary search coz we need (log n) time complexity

        //only one element thats the peak
        if(nums.size()==1){
            return 0;
        }
        //if peak is the first element, the next element should be less than it
        if(nums[0]>nums[1]){
            return 0;
        }
        //if peak is the last element, the previous element should be less than it
        if(nums[nums.size()-1]>nums[nums.size()-2]){
            return nums.size()-1;
        }
        //binary search the array for peak
        int left = 1;
        int right = nums.size()-2;
        while (left<=right){
            int mid = left+(right-left)/2;
            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){
                return mid; //if mid is the peak return it
            }
            //if mid is on the increasing curve that means peak is on right
            else if(nums[mid+1]>nums[mid]){
              left = mid + 1;
              //if mid is on the decreasing curve that means peak is on left
            }else{
                right = mid - 1;
            }
        }
        return -1;
    }
};