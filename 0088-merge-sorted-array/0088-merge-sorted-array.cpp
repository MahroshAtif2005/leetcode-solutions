class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

//If nums1[i] is larger, put it at nums1[p] and decrement i.
//Otherwise, put nums2[j] at nums1[p] and decrement j.
//In either case, decrement p, because we've filled one position.

     int i = m-1;
     int j = n-1;
     int p = nums1.size()-1;

     while(i>=0 && j>=0){
        if(nums2[j]>nums1[i]){
            nums1[p]=nums2[j];
            j--;
        }else{
            nums1[p]=nums1[i];
            i--;
        }
        p--;
     }

     while(j>=0){
        nums1[p]=nums2[j];
        j--;
        p--;
     }
    }
};