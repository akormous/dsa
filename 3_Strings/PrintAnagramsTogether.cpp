// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        vector<vector<string>> result;
        // sort each string
        vector<string> sorted_list;
        
        for(int i = 0; i < string_list.size(); ++i) {
            string temp = string_list[i];
            sort(temp.begin(), temp.end());
            sorted_list.push_back(temp);
        }

        // a hashmap that maps string to indices
        unordered_map<string, vector<int>> m;
        for(int i = 0; i < sorted_list.size(); ++i) {
            m[ sorted_list[i] ].push_back(i);
        }

        // push the original strings to result
        unordered_map<string, vector<int>>::iterator it;
        for(it = m.begin(); it != m.end(); ++it) {
            vector<string> temp;
            for(auto i : it->second) {
                temp.push_back( string_list[i] );
            }
            result.push_back(temp);
        }
        
        
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
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends