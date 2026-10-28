class Solution {
public:   
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
      int r = click[0];
      int c = click[1];

      if(board[r][c]=='M'){
        board[r][c]='X';
        return board;
      }

      dfs(board,r,c);
      return board;
    }

    void dfs(vector<vector<char>>& board,int r,int c){
        //base case
        if(r<0 ||c<0 ||r>=board.size()||c>=board[0].size()||board[r][c]!='E'){
            return;
        }
         int count = 0;
        for(int i = r-1; i<=r+1;i++){
            for(int j = c-1; j<=c+1;j++){
                if(i>=0 && j>=0 && i<board.size()&&j<board[i].size()&&board[i][j]=='M'){
                    count++;
                }
            }
        }

        if(count>0){
            board[r][c]='0'+count;
            return;
        }

        board[r][c]='B';

        dfs(board,r+1,c);
        dfs(board,r-1,c);
        dfs(board,r,c-1);
        dfs(board,r,c+1);

        //diagonal dfs
        dfs(board,r+1,c+1);
        dfs(board,r-1,c-1);
        dfs(board,r+1,c-1);
        dfs(board,r-1,c+1);
    }
};