class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    vector<unordered_set<char>> rows(9);
    vector<unordered_set<char>> cols(9);
    vector<unordered_set<char>> boxes(9);

 for (int i = 0; i<9; i++){
  for (int j = 0; j<9; j++){
     char current = board[i][j];
     if(current=='.'){
      continue;
     }
// i/3 gives which box-row we're in
// multiply by 3 because there are 3 boxes per row
// j/3 gives which box-column we're in
// ADD the box-column
     int boxindex = (i/3) *3 + (j/3) ; 

     if(rows[i].count(current) || cols[j].count(current)||boxes[boxindex].count(current)){
         return false;
     }
     rows[i].insert(current);
     cols[j].insert(current);
     boxes[boxindex].insert(current);
  }
 }
 return true;
    }
};