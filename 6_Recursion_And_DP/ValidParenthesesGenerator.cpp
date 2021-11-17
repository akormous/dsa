/*

Parens: Implement an algorithm to print all valid (e.g., properly opened and closed) combinations
of n pairs of parentheses
EXAMPLE
Input: 3
Output: ( ( () ) ) , ( () () ) , ( () ) () , () ( () ) , () () ()

Approach:
We keep track of number of opening and closing bracket in the current string

for n pairs of parentheses,
there will be n opening brackets and n closing brackets
and closing brackets should always come after opening brackets

at any point in time,
number of closing brackets should never be greater than number of opening brackets

Now, look at the code


*/

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void generator(int n, int open, int close, string cur, vector<string>& res) {
        if(open == n && close == n) {
            res.push_back(cur);
            return;
        }

        // add an opening bracket
        if(open < n)
            generator(n, open+1, close, cur + "(", res);

        // add a closing bracket
        if(close < open)
            generator(n, open, close+1, cur + ")", res);
    }
    vector<string> AllParenthesis(int n) 
    {
        vector<string> result;
        generator(n, 0, 0, "", result);
        return result;
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends