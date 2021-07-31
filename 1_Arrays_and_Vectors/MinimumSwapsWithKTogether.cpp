// { Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <iostream>
using namespace std;


int minSwap(int *arr, int n, int k);

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        cout << minSwap(arr, n, k) << "\n";
    }
	return 0;
}
// } Driver Code Ends


int minSwap(int *arr, int n, int k) {
    // approach is to use sliding window to keep track of number of elements greater than k
    // the size of window would be the number of elements smaller than or equal to k

    // Step 1: count the number of elements <= k
    int window_size = 0;
    for(int i = 0; i < n; i++)
        if(arr[i] <= k)
            window_size++;
    
    // Step 2: Now we know the window size in which we need to see how many elements need swapping
    // so we count number of unwanted elements in the first window
    int unwanted_count = 0;
    for(int i = 0; i < window_size; i++)
        if(arr[i] > k)
            unwanted_count++;
    
    // Step 3: Look in each window, and check if a good element is there then decrease the count of unwanted elements
    // basically we need to minimize unwanted_count
    int answer = unwanted_count;
    for(int i = 0, j = window_size; j < n; i++, j++) {
        if(arr[i] > k)
            unwanted_count--;
        if(arr[j] > k)
            unwanted_count++;
        
        // keep track of the minimum unwanted count in a window
        answer = min(answer, unwanted_count);
    }
    return answer;
}