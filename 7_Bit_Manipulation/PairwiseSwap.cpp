// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/*
Question: Swap odd and even bits in an integer

Approach: Just imagine a binary number
9 8 7 6 5 4 3 2 1 0
1 1 0 0 1 0 1 0 1 1

So, what we need to do is just swap the odd positioned bits to even positioned bits
how to do this?
Swap the adjacent bits, example
swap(bit_0, bit_1)
swap(bit_2, bit_3)
swap(bit_4, bit_5)
swap(bit_6, bit_7)
and so on

Result will be 
9 8 7 6 5 4 3 2 1 0
1 1 0 0 0 1 0 1 1 1


How can we obtain all the odd positioned bits by using a mask?
9 8 7 6 5 4 3 2 1 0
1 1 0 0 1 0 1 0 1 1 = number
0 1 0 1 0 1 0 1 0 1 = AND mask, so a sequence like 01010101010101 will do the trick

we will just left shift this by 1, and add it to an empty binary number.
Similarly, we will extract all the odd positioned bits, and add it to our result

How to generate a sequence like 0101010101010101...
Just remember
BINARY                  HEXADECIMAL
010101010101010101... = 0x5555555555555....
101010101010101010... = 0xAAAAAAAAAAAAA....

*/
 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to swap odd and even bits.
    unsigned int swapBits(unsigned int n)
    {
    	int oddBits = n & 0x55555555;
        int evenBits = n & 0xAAAAAAAA;

        // left shift oddBits by 1
        oddBits = oddBits << 1;

        // right shift evenBits by 1
        evenBits = evenBits >> 1;

        return (oddBits | evenBits);
    }
};

// { Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;//testcases
	while(t--)
	{
		unsigned int n;
		cin>>n;//input n
		
		Solution ob;
		//calling swapBits() method
		cout << ob.swapBits(n) << endl;
	}
	return 0;
}  // } Driver Code Ends