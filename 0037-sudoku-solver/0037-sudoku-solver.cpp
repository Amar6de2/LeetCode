/*
This is the solution to solve a sudoku puzzle.
Sudoku Puzzle generally conists of 9*9 grid with numbers appearing in some of the squares and there are 9 (3*3) square grids contained in them.3 conditions are to be followed while filling the rest of the numbers.
1)Each row must be filled with numbers 1 to 9 without repeating any numbers.
2)Each column needs to be filled with 1-9 without repeating any number.
3)Each square must contain numbers from 1-9 without repeating any of the number.
*/
class Solution {
public:
    bool satisfies(vector<vector<char>> board,char ch,int row,int col)
    { 
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==ch)
            {return false;}
            if(board[i][col]==ch)
            {return false;}
            if(board[3*(row/3)+(i/3)][3*(col/3)+i%3]==ch)
            {return false;}
        }
       return true;
    }
    bool solve(vector<vector<char>> &board)
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]=='.')
                {
                    for(char ch='1';ch<='9';ch++)
                    {
                        if(satisfies(board,ch,i,j)==true)
                        {
                            board[i][j]=ch;
                            if(solve(board)==true)
                           {return true;}
                            else
                            {board[i][j]='.';}//backtracking step
                          }
                        
                    }
                    return false;//return false in case of any null character
                    
                }}}
                return true;}//return true only when there are no null pointer in our board.
                
    void solveSudoku(vector<vector<char>>& board) {
      bool ans= solve(board);
         }
};