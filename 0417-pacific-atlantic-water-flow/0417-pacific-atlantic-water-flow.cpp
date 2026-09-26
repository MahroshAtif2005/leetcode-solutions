class Solution {
public:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited,int r,int c, int prevHeight){
        int rows = heights.size();
        int cols = heights[0].size();
        if(r<0||c<0||r>=rows||c>=cols||visited[r][c]||heights[r][c]<prevHeight){
            return;
        }

        visited[r][c]=true;

      int currentHeight = heights[r][c];

      dfs(heights,visited,r-1,c,currentHeight);
      dfs(heights,visited,r+1,c,currentHeight);
      dfs(heights,visited,r,c-1,currentHeight);
      dfs(heights,visited,r,c+1,currentHeight);

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
      int rows = heights.size();
      int cols = heights[0].size();

      vector<vector<bool>> pacific(rows,vector<bool>(cols,false));
      vector<vector<bool>> atlantic(rows,vector<bool>(cols,false));

      for (int r = 0; r<rows; r++){
        //left n right
        dfs(heights,pacific,r,0,heights[r][0]);
        dfs(heights,atlantic,r,cols-1,heights[r][cols-1]);
      }
      for (int c = 0; c<cols; c++){
        //up and down
        dfs(heights,pacific,0,c,heights[0][c]);
        dfs(heights,atlantic,rows-1,c,heights[rows-1][c]);
      }
      vector<vector<int>> answer;
      for (int r = 0; r<rows;r++){
        for(int c = 0; c<cols; c++){
            if(pacific[r][c]&&atlantic[r][c]){
            answer.push_back({r,c});
            }
        }
      }
      return answer;
    }
};