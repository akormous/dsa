#include<bits/stdc++.h>
using namespace std;

/*
Question - 
Zero Matrix: Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
column are set to 0.
*/

/*

Input-

3 * 4

1 2 3 4
5 0 7 8
0 4 3 2

Output-
0 0 3 4
0 0 0 0
0 0 0 0


Approach - 
If any element is 0, then set the first element in the row and col to 0

In the next iteration, if you find any 0, then set its entire row and col to 0

NOTE: Check the 0th row and 0th col separately because if changed, it will affect the rest of the elements

*/
void displayMatrix(vector<vector<int>> mat) {
    int m = mat.size();
    int n = mat[0].size();
    for(auto i : mat) {
        for(auto j : i)
            cout<<j<<" ";
        cout<<endl;
    }
}

void zeroMatrix(vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat[0].size();

    bool row_flag = false;
    bool col_flag = false;

    // check 0th row and 0th col separately
    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < cols; col++) {
            if(row == 0 && mat[row][col] == 0)
                row_flag = true;
            
            if(col == 0 && mat[row][col] == 0)
                col_flag = true;

            if(mat[row][col] == 0) {
                mat[0][col] = 0;
                mat[row][0] = 0;
            }
        }
    }


    // traverse all the middle elements again 
    // and if the first element of the row and col is zero
    // then set it to zero
    for(int row = 1; row < rows; row++) {
        for(int col = 1; col < cols; col++) {
            if(mat[0][col] == 0 || mat[row][0] == 0) {
                mat[row][col] = 0;
            }
        }
    }

    // if row_flag was set
    if(row_flag == true) {
        for(int col = 0; col < cols; col++)
            mat[0][col] = 0;
    }

    // col_flag was set
    if(col_flag == true) {
        for(int row = 0; row < rows; row++) {
            mat[row][0] = 0;
        }
    }
}



int main() {
    int m, n;
    cin>>m>>n;
    vector<vector<int>> mat(m, vector<int>(n));
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin>>mat[i][j];

    zeroMatrix(mat);
    cout<<endl;

    displayMatrix(mat);
    cout<<endl;
    return 0;
}