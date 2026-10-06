class Solution {
public:
void printsudoku(vector<vector<char>>& board){
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){
            cout<<board[i][j]<<"";
        }
        cout<<endl;
    }
}
bool isSafe(vector<vector<char>>& board, int row, int col, int digit)
{
    // Check row
    for (int j = 0; j < 9; j++)
    {
        if (board[row][j] == digit)
        {
            return false;
        }
    }

    // Check column
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == digit)
        {
            return false;
        }
    }

    // Check 3x3 box
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    for (int i = startRow; i < startRow + 3; i++)
    {
        for (int j = startCol; j < startCol + 3; j++)
        {
            if (board[i][j] == digit)
            {
                return false;
            }
        }
    }

    return true;
}

bool sudokusolver(vector<vector<char>>& board,int row,int col){
    if(row==9){
        //sudoku solve
       printsudoku(board);
        return true;
    }
    int nextRow = row;
    int nextCol = col+1;
    if(col+1==9){
        nextRow = row +1;
        nextCol = 0;
    }
    if(board[row][col]!='.'){
        return sudokusolver(board,nextRow,nextCol);
    }
    for(char digit = '1';digit<='9';digit++){
        if(isSafe(board,row,col,digit)){
            board[row][col]=digit;
            if(sudokusolver(board,nextRow,nextCol)){
                return true;
            }
        board[row][col]='.';
        }
    }
    return false;
}
    void solveSudoku(vector<vector<char>>& board) {
          sudokusolver(board,0,0);
         
        
    }
};