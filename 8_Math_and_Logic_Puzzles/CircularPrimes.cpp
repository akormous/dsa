// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
class Solution{

 // } Driver Code Ends
	public:
	// creates a number from the given digits
	int createNumber(vector<int> digits) {
	    int num = 0;
	    for(auto i : digits)
	        num = num*10 + i;
	   return num;
	}

    vector<int> extractDigits(int n) {
        vector<int> digits;
	    while(n) {
	        digits.push_back(n%10);
	        n /= 10;
	    }
        reverse(digits.begin(), digits.end());
        return digits;
    }
	
	int isCircularPrime(int n) {
	    // Code here
	    if(n == 1)
	        return 0;
	    
        // get all the circular permutations
        vector<int> digits = extractDigits(n);
        // store all circular numbers in an array and keep track of max
        vector<int> permutations;
        int maxNum = INT_MIN;
        for(int i = 0; i < digits.size(); ++i) {
            // store the current number
            int num = createNumber(digits);
            maxNum = max(maxNum, num);

            permutations.push_back( num );

            // put the MSD at the end
            int msd = digits[0];
            digits.erase(digits.begin());
            digits.push_back(msd);
        }

        // do Sieve of Eratosthenes on maxNum,
        // in this way we will cover all the permutations
        bool SOE[maxNum + 1];
        memset(SOE, 0, sizeof(SOE));
        // 0 = prime, 1 = non-prime
        int i = 2;
        while(i <= sqrt(maxNum)) {
            if(SOE[i] == 0) {
                int j = 2*i;
                while(j <= maxNum) {
                    SOE[j] = 1;
                    j += i;
                }
            }
            ++i;
        }

        // go through the permutations and check if they are prime
        for(auto it : permutations) {
            
            if(SOE[it] == 1)
                return false;
        }
        return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.isCircularPrime(n);
		cout << ans <<"\n";
	}  
	return 0;
}  // } Driver Code Ends