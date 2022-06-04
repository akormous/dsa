#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool contains(unordered_set<int>& iSet, int iVal) {
        return (iSet.find(iVal) != iSet.end());
    }
    void solve(vector<string>& board, int row, int n, vector<vector<string>>& result) {
        if(row == n) {
            result.push_back(board);
            return;
        }
        
        // in the current row, try to put queen in each of the columns
        for(int c = 0; c < n; c++) {
            // if the position is invalid
            if(board[row][c] == 'Q' || contains(cols, c) 
               || contains(posDiag, row + c) || contains(negDiag, row - c))
                continue;
            
            // put the queen at current position
            board[row][c] = 'Q';
            // add things to the caches
            cols.insert(c);
            posDiag.insert(row + c);
            negDiag.insert(row - c);
            
            // recurse for the next column
            solve(board, row+1, n, result);
            
            // remove, backtrack, so that next configurations can be found
            board[row][c] = '.';
            // remove things from the caches
            cols.erase(c);
            posDiag.erase(row + c);
            negDiag.erase(row - c);
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n,'.'));    // the chess board
        
        vector<vector<string>> result;  // all the possible board configurations
        
        solve(board, 0, n, result);    // call the backtracking function starting with 0th row
        
        return result;
    }
private:
    unordered_set<int> cols;  // tracks queens in column nos, each col can have only 1 queen
    unordered_set<int> posDiag; // tracks queens in positive diagonals (key = r + c)
    unordered_set<int> negDiag; // tracks queens in negative diagonals (key = r - c)
};