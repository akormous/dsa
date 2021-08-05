// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        /*
        Test Case - 
3 5
6 6 2 28 2 12 26 3 28 7 22 25 3 4 23

6 6 2 28 2
12 26 3 28 7
22 25 3 4 23

        */
        vector<int> answer;
        int row_start = 0;
        int row_end = r;
        int col_start = 0;
        int col_end = c;

        while(row_start < row_end && col_start < col_end) {
            int i;
            // move right
            for(i = col_start; i < col_end; i++)
                answer.push_back(matrix[row_start][i]);
            row_start++;

            // move down
            for(i = row_start; i < row_end; i++)
                answer.push_back(matrix[i][col_end - 1]);
            col_end--;
            

            // move left
            if(row_start < row_end) {
                for(i = col_end - 1; i >= col_start; i--)
                    answer.push_back(matrix[row_end - 1][i]);
                row_end--;
            }
                
            // move up
            if(col_start < col_end) {
                for(i = row_end - 1; i >= row_start; i--)
                    answer.push_back(matrix[i][col_start]);
                col_start++;
            }
            
        }
        return answer;
    }

};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends