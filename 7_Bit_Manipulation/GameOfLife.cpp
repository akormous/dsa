#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
/*
The approach is to store the next state in the 2nd bit position,
and after all cells are processed, shift each cell to the right by 1 bit
*/
    int getNeighborCount(vector<vector<int>>& board, int r, int c) {
        vector<int> dr = {1, 1, 0,-1,-1,-1, 0, 1};
        vector<int> dc = {0, 1, 1, 1, 0,-1,-1,-1};
        int count = 0;
        
        for(int i = 0; i < dr.size(); ++i) {
            int rr = r + dr[i];
            int cc = c + dc[i];
            
            if(rr < 0 || rr >= board.size() || cc < 0 || cc >= board[0].size() ) continue;
            // compare the 1st bit only
            if((board[rr][cc] & 1) == 0)  continue;
            count++;
        }
        return count;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                // get number of neighbors
                int count = getNeighborCount(board, i, j);
                
                switch(board[i][j]) {
                    case 0:
                        if(count == 3)
                            board[i][j] = board[i][j] | 2;
                        break;
                    case 1:
                        if(count == 2 || count == 3)
                            board[i][j] = board[i][j] | 2;
                        break;
                    default:    break;
                }
            }
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                board[i][j] >>= 1;
            }
        }
    }
};