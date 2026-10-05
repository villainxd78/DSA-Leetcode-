class Solution {
public:
    bool isSafe(int row,int col,int n,vector<string>&board){
      int duprow = row;
      int dupcol = col;

      while(row>=0&& col>=0){
        if(board[row][col]=='Q'){
            return false;
        }
        row--;
        col--;
      }
      row= duprow;
      col = dupcol;

      while(col>=0){
        if(board[row][col]=='Q')return false;
      col--;
      }
     

      row = duprow;
      col = dupcol;
      while(row<n && col>=0){
        if(board[row][col]=='Q'){
            return false;
        }
        row++;
        col--;
      }
      return true;
    }
     void solve(int col,vector<string>&board,int n,int& count){
        if(col==n){
            count++;
            return;
        }
        for(int row =0;row<n;row++){
            if(isSafe(row,col,n,board)){
                board[row][col]='Q';
                solve(col+1,board,n,count);
                board[row][col]='.';
            }
        }
        return;
     }
    int totalNQueens(int n) {
        vector<string>board(n);
        string s(n,'.');
        for(int i = 0;i<n;i++){
            board[i]=s;
        }
        int count = 0;
        solve(0,board,n,count);
        return count;
    }
};