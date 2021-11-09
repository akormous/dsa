// { Driver Code Starts
//Initial Template for C++

/*
Question: https://practice.geeksforgeeks.org/problems/974612adac31d8e35448df5879342690f841c532/1
*/

#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    
    public:
    int sumOfDigits(int n) {
        int sum = 0;
        while(n) {
            sum += n%10;
            n /= 10;
        }
        return sum;
    }
    int RulingPair(vector<int> arr, int n) 
    { 
    	// Your code goes here
    	// maps sum of digits to the numbers in arr
    	unordered_map<int, vector<int>> m;
    	for(auto i : arr) {
    	    m[sumOfDigits(i)].push_back(i);
    	}
    	
    	// go through each vector, find the largest 2 numbers and get the max among the vectors
    	int ability = -1;
    	
    	unordered_map<int, vector<int>>::iterator it;
    	
    	for(it = m.begin(); it != m.end(); ++it) {
            vector<int> temp = it->second;    	    
    	    if(temp.size() > 1) {

    	        sort(temp.begin(), temp.end(), -1);
    	        ability = max(ability, temp[0] + temp[1]);
    	    }
    	    
    	}
    	return ability;
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
		vector<int> arr(n);
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
	    Solution obj;
		cout << obj.RulingPair(arr,n)<<"\n";
	}
	return 0; 
} 

  // } Driver Code Ends