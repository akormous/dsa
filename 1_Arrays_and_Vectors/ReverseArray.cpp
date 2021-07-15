// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


string reverseWord(string str);


int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}

// } Driver Code Ends


//User function Template for C++

string reverseWord(string str){
    int n = str.length();
  //Your code here
  for(int i=0; i<n/2; i++)
  {
      char temp = str[i];
      str[i] = str[n-1-i];
      str[n-1-i] = temp;
  }
  return str;
  
}