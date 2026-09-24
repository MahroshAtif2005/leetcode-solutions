class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        queue<pair<int,int>> q;
        int fresh = 0;

        //find all the initially rotten oranges
        //and fount fresh oranges
        for (int r = 0; r<rows; r++){
            for (int c = 0; c<cols;c++){
                if (grid[r][c]==2){
                    q.push({r,c});
                }else if(grid[r][c]==1){
                    fresh++;
                }
            }
        }
        int minutes = 0;
        //do bfs (multi-source bfs)
        
        while (!q.empty() && fresh>0){
            int size = q.size();
            //process all the oranges that are rotten in the CURRENT minute
            for (int i = 0; i<size ; i++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                //Up
                if((r-1>=0) && grid[r-1][c]==1){
                    grid[r-1][c]=2;
                    fresh--;
                    q.push({r-1,c});
                }
                //Down
                if((r+1<rows) && grid[r+1][c]==1){
                    grid[r+1][c]=2;
                    fresh--;
                    q.push({r+1,c});
                }
                //Left
                if(c-1>=0 && grid[r][c-1]==1){
                    grid[r][c-1]=2;
                    fresh--;
                    q.push({r,c-1});
                }
                //Right
                if(c+1<cols && grid[r][c+1]==1){
                    grid[r][c+1]=2;
                    fresh--;
                    q.push({r,c+1});
                }
            }
         minutes++;
        }
         if(fresh>0){
            return -1;
         }
         return minutes;
        }    
};