// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    vector<pair<int,int>> hanoi;
    void makeMove(int start, int end) {
        hanoi.push_back( make_pair(start, end) );
    }
    /*
    N = number of plates
    start = from where to pick up the plate
    end = where to put the picked plate
    */
    void towersOfHanoi(int N, int start, int end) {
        if(N == 1) {
            makeMove(start, end);
            return;
        }
            

        int other = 6 - (start + end);

        towersOfHanoi(N-1, start, other);
        makeMove(start, end);
        towersOfHanoi(N-1, other, end);
    }
    // N = number of plates
    // n = nth move
    vector<int> shiftPile(int N, int n){
        // code here
        towersOfHanoi(N, 1, 3);

        vector<int> result = {hanoi[n].first, hanoi[n].second};
        return result;

    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, n;
        cin>>N>>n;
        
        Solution ob;
        vector<int> ans = ob.shiftPile(N, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends