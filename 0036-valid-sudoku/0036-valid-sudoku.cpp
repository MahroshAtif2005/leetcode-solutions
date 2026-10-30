class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       vector<unordered_set<char>> rows(9);
       vector<unordered_set<char>> cols(9);
       vector<unordered_set<char>> boxes(9);

       for(int r = 0; r<board.size(); r++){
        for(int c = 0; c<board[0].size(); c++){
            if(board[r][c]=='.') continue;
           
           int boxIndex = (r/3) * 3 + (c/3);
           int current = board[r][c];

           if(rows[r].count(current)||cols[c].count(current)||boxes[boxIndex].count(current)){
            return false;
           }

           rows[r].insert(current);
           cols[c].insert(current);
           boxes[boxIndex].insert(current);
        }
       }
       return true;
    }
};