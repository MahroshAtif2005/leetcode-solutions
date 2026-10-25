class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int r = 0; r<board.size(); r++){
            for(int c = 0; c<board[0].size(); c++){
                if(board[r][c]==word[0]){
                   if (dfs(board, word, r, c, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int r, int c,int idx){
        //all indices matched
        if(idx == word.size()){
            return true;
        }
        if(r<0 || c<0 || r>=board.size() || c>=board[0].size()||
          board[r][c] != word[idx]){
            return false;
        }
        
        //save current char
        char temp = board[r][c];
        //mark as vidited
        board[r][c]='#';


        //explore all 4 directions
        bool found = dfs(board,word,r-1,c,idx+1)||
                     dfs(board,word,r+1,c,idx+1)||
                     dfs(board,word,r,c-1,idx+1)||
                     dfs(board,word,r,c+1,idx+1);

        board[r][c]=temp;

        return found;
    }
};