#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        /*
        create 3 structures - for rows, columns and boxes
        these structures tell if a number in a particular row, col, or box is used or not
        */
        bool rowTracker[9][9] = {false}, colTracker[9][9] = {false}, boxTracker[9][9] = {false};

        // traverse the board
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] == '.')  continue;   // skip empty spaces
                /*
                Here,
                i = row number
                j = col number
                k = box number
                n = cur number to be processed
                */
                int n = board[i][j] - '0' - 1;
                int k = 3*(i/3) + (j/3);

                // if current number is already occupied in row, col or box
                if(rowTracker[i][n] || colTracker[j][n] || boxTracker[k][n])
                    return false;
                // else track these positions
                rowTracker[i][n] = colTracker[j][n] = boxTracker[k][n] = true;
            }
        }
        return true;
    }
};