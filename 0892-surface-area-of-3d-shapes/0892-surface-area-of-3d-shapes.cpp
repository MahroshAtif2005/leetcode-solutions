class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int area = 0;

        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
               int h = grid[i][j];

               if (h==0) continue;

               area += 4*h+2; //4 sides x height and 2 (upwards and bottom face)
                
                //remove hidden faces with tower above
               if(i>0){
                 area-= 2 * min(h,grid[i-1][j]);
               }

               //remove hidden faces wiht tower to the left
               if(j>0){
                area-= 2 * min(h,grid[i][j-1]);
               }


            }
        }
        return area;
    }
};