// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int> > stockBuySell(vector<int> A, int n){
        // so apparently in this question the number of transactions allowed are infinite,
        // we can buy and sell stock any number of times but they should not overlap
        // valley peak approach
        // we find the buying day which will be the least so far point, we buy the stock on that day
        // after that day, we find the selling day, which will be the peak until it starts to decrease

        // resulting pair of days to maximize profit
        vector<vector<int>> result;

        int day = 0;    // start from the 0th day

        // while we reach the last possible buying day
        while(day < n-1) {
            int b = -1; // buying day
            int s = -1; // selling day

            while(day < n-1 && A[day + 1] <= A[day])
                day++;
            
            // if we reach the last day, then break
            if(day == n-1)
                break;

            // buying point will be this day aka valley
            b = day;

            day++;  // start searching for selling day from the next day of buying
            while(day < n && A[day] >= A[day - 1])
                day++;
            s = day - 1; // this will be the selling point

            // push this pair of buy day and sell day
            result.push_back({b,s});
        }
        return result;
    }
};

// { Driver Code Starts.

int check(vector<vector<int>> ans, vector<int> A, int p)
{
    int c = 0;
    for(int i=0; i<ans.size(); i++)
        c += A[ans[i][1]]-A[ans[i][0]];
    return (c==p) ? 1 : 0;
}

int main()
{   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        for (int i=0; i<n; ++i){
            cin>>A[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.stockBuySell(A, n);
        int p = 0;
        for(int i=0; i<n-1; i++)
        {
            int x = A[i+1]-A[i];
            if(x>0)
                p += x;
        }
        if(ans.size()==0)
            cout<<"No Profit";
        else{
            cout<<check(ans,A,p);
        }cout<<endl;
    }
    return 0;
}

  // } Driver Code Ends