class Solution {
public:

    void dfs(int r, int c, vector<vector<char>>& board){

       if(r<0 || c<0 || r>=board.size() ||c>=board[0].size() || board[r][c]=='.'){
         return; //base case
       }
       
       board[r][c] = '.';

       dfs(r+1,c,board);
       dfs(r-1,c,board);
       dfs(r,c+1,board);
       dfs(r,c-1,board);
    }


    int countBattleships(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();
        int battleships = 0;

        for(int r = 0; r<board.size(); r++){
           for(int c = 0; c<board[0].size(); c++){
            if(board[r][c]=='X'){
              battleships++;
              dfs(r,c,board);
            }
           } 
        }

        return battleships;
    }
};