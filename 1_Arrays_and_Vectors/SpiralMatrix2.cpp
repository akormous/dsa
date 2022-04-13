#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void changeDirection(int& rowDir, int& colDir) {
        /**
        This function changes the current direction
        It takes a right turn
        */
        // if cur direction is right, then move down
        if(rowDir == 0 && colDir == 1) {
            rowDir = 1; colDir = 0;
        }
        // if cur direction is down, then move left
        else if(rowDir == 1 && colDir == 0) {
            rowDir = 0; colDir = -1;
        }
        // if cur direction is left, then move up
        else if(rowDir == 0 && colDir == -1) {
            rowDir = -1; colDir = 0;
        }
        // if cur direction is up, then move right
        else if(rowDir == -1 && colDir == 0) {
            rowDir = 0; colDir = 1;
        }
    }
    
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        
        int num = 1;
        int i = 0;
        int j = 0;
        
        // intial direction to move in - right
        int rowDir = 0;
        int colDir = 1;
        
        while(num <= (n*n)) {
            // fill the number in the matrix
            result[i][j] = num;
            
            int nextRow = i + rowDir;
            int nextCol = j + colDir;
            
            if(nextRow < 0 || nextRow >= n || nextCol < 0 || nextCol >= n || result[nextRow][nextCol] != 0)
                changeDirection(rowDir, colDir);
            
            i += rowDir;
            j += colDir;
            num++;
        }
        return result;
    }
};