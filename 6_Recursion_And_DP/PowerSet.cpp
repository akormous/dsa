// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/*

Power Set: Return the power set of a given string.

A power set of n elements contains 2^n elements

Approach:
1. Allocate space for power set
*/

 // } Driver Code Ends
class Solution{
	public:
        vector<string> result;
        void powerSet(string s, int index, string cur) {
            if(index == s.length()) {
                if(cur != "")
                    result.push_back(cur);
                return;
            }

            // there are 2 cases
            

            // exclude the current char
            powerSet(s, index+1, cur);
            
            // include the current char
            powerSet(s, index+1, cur + s[index]);
        }
		vector<string> AllPossibleStrings(string s){
		    // Code here
            powerSet(s, 0, "");
            sort(result.begin(), result.end());
            return result;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends