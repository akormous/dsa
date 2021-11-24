#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<char>> answer;
    void saveState(vector<vector<char>> board) {
        for(int i = 0; i < 9; ++i) {
            vector<char> temp;
            for(int j = 0; j < 9; ++j) {
                temp.push_back(board[i][j]);
            }
            answer.push_back(temp);
        }
    }
    // checks if a value is valid at current position in sudoku
    // it should not be in the row, col and submatrix
    bool isValid(vector<vector<char>> board, int x, int y, char val) {
        // check in the row
        for(int j = 0; j < 9; ++j) {
            if(board[x][j] == val)
                return false;
        }
        // check in the column
        for(int i = 0; i < 9; ++i) {
            if(board[i][y] == val)
                return false;
        }

        // find the left-topmost point in each submatrix by the formula
        // smx = x/3 * 3;   smy = y/3 * 3;
        int smx = x/3 * 3;
        int smy = y/3 * 3;
        // check for value in the submatrix
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                if(board[smx + i][smy + j] == val)
                    return false;
            }
        }
        return true;
    }

    // a utility function to solve sudoku
    bool solveSudokuUtility(vector<vector<char>>& board, int i, int j) {
        // if the board is in a valid state
        if(i == 9) {
            return true;
        }

        // calculate which point to process next
        int ni, nj; // next i and next j
        // if we are at the last column
        if(j == 8) {
            ni = i+1;
            nj = 0;
        }
        else {
            ni = i;
            nj = j + 1;
        }


        // check if current position is already filled 
        if(board[i][j] != '.') {
            // then move to the next position
            if(solveSudokuUtility(board, ni, nj))
                return true;
        }
        // else if position is empty
        else {
            // check for every possible value, and try to fill it
            for(int num = 1; num <= 9; ++num) {
                // if the current value is valid
                if(isValid(board, i, j, '0' + num) == true) {

                    board[i][j] = '0' + num;

                    if(solveSudokuUtility(board, ni, nj))
                        return true;

                    board[i][j] = '.';
                }
                
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuUtility(board, 0, 0);

        return;
    }
};