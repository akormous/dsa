// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>> ans;
    // returns the rows where the queens are places
    vector<int> getQueenRows(vector<vector<bool>> board) {
        int n = board.size();
        vector<int> res;
        // go to each col
        for(int j = 0; j < n; j++) {
            // find the queen in each col, by going through the rows
            for(int i = 0; i < n; i++) {
                if(board[i][j] == 1) {
                    res.push_back(i + 1);
                    break;
                }
            }
        }
        return res;
    }

    void solve(int col, vector<vector<bool>> board, int n, vector<bool> leftRow, vector<bool> lowerDiag, vector<bool> upperDiag) {
        
        // base case
        if(col == n) {
            // means some success happening here
            ans.push_back(getQueenRows( board ));
            return;
        }
        // go to each row
        for(int row = 0; row < n; row++) {
            // check if its a safe position
            // by checking leftRow, upperDiag and lowerDiag
            if(leftRow[row] == 0 && 
                upperDiag[n - 1 + col - row] == 0 &&
                lowerDiag[row + col] == 0) {

                // place a queen and block row, lowerDiag, upperDiag
                board[row][col] = 1;
                leftRow[row] = 1;
                upperDiag[n - 1 + col - row] = 1;
                lowerDiag[row + col] = 1;

                // recurse for next column
                solve(col + 1, board, n, leftRow, lowerDiag, upperDiag);

                // remove the queen and unblock row, lower and upper diags
                board[row][col] = 0;
                leftRow[row] = 0;
                upperDiag[n - 1 + col - row] = 0;
                lowerDiag[row + col] = 0;
            }
        }

    }
    vector<vector<int>> nQueen(int n) {
        // code here
        // a chess board n x n
        vector<vector<bool>> board(n, vector<bool>(n, 0));

        // 1 = queen, 0 = empty
        /*
        Setting up certain hashes, to check if there is a queen in the
        current row
        upper diagonal
        lower diagonal
        These are to ensure that no queen attacks each other
        */
        /* hash for left row
        this tells if there is a queen in ith row,
        so if leftRow[i] == 1, it means that there is a queen in ith row
        which means we cannot place queen in the same row
        */
        vector<bool> leftRow(n, 0);

        /* hash for upper diagonal
        this tells if there is any queen in the upper diagonal of where we are currently
        so 2*n-1 can map every upper diagonal in a nxn matrix
        upperDiag[n - 1 + col - row] == 1, then there is a queen in the upperdiag
        */
        vector<bool> upperDiag(2*n - 1, 0);

        /* hash for lower diagonal
        this tells if there is any queen in the lower diagonal of where we are currently
        2*n-1 can map every lower diagonal in a nxn matrix
        lowerDiag[row + col] == 1, then there is a queen in the lowerdiag
        */
        vector<bool> lowerDiag(2*n - 1, 0);

        // the basic intuition is recursion and backtracking, 
        // check if a queen can be placed,
        // put a queen there
        // move to the next column and recurse
        // remove the queen
        solve(0, board, n, leftRow, lowerDiag, upperDiag);

        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends