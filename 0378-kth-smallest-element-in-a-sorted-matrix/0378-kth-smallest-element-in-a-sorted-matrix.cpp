class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
     //this can be done with priority  queue or binray search pq solution is
     //with priority queue the time complexity is O(n² log k) and O(k) extra space
     //with binary search on values: O(n log (value range)) and O(1) extra space
     //sorted gives us a hint that we can use binary search
     int low = matrix[0][0];
     int high = matrix[matrix.size()-1][matrix[0].size()-1];

     while (low<high){
        int mid = low+(high-low)/2;
        int count = 0;
        
        int row = matrix.size()-1;
        int col = 0;

        while (row>=0 && col<matrix[0].size()){
           if(matrix[row][col]<=mid){
             count+= row+1;
             col++;
           }else{
            row--;
           }
        }
        if(count<k){
           low = mid+1;
        }else{
            high = mid;
        }
     }
     return low;
    }
};