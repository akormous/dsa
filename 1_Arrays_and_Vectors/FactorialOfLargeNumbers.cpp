// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int N){
        // code here
        vector<int> result;
        result.push_back(1);
        if(N == 1) {
            return result;
        }
        // start from 2
        for(int i = 2; i <= N; i++) {
            // go through the product digit by digit
            // if there is any carry then add it to the next digit
            int carry = 0;
            for(int j = 0; j < result.size(); j++) {
                int temp = i*result[j] + carry;
                result[j] = temp%10;
                carry = temp/10;
            }
            while(carry) {
                result.push_back(carry%10);
                carry = carry/10;
            }
                
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends