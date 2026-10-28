class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
     int battleships = 0;
     for(int r = 0; r<board.size(); r++){
        for(int c = 0; c<board[0].size(); c++){
            if(board[r][c]=='.') continue;
            if(r>0 && board[r-1][c]=='X') continue;
            if(c>0 && board[r][c-1]=='X') continue;
            battleships++;
        }
     }
     return battleships;
    }
};