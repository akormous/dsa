#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // another approach is to consider the 2d ordered matrix as a single container
        // basically mapping the coords of a 2d matrix into a linear container
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int start = 0, end = rows*cols - 1;
        while(start <= end) {
            int mid = ( start + end )/ 2;
            int cur_val = matrix[mid/cols][mid%cols];
            if(cur_val == target)
                return true;
            if(cur_val < target)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return false;
    }
};