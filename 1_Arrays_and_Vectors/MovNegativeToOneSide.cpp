// A C++ program to put all negative
// numbers before positive numbers
#include <bits/stdc++.h>
using namespace std;

// A utility function to print an array
void printArray(int arr[], int n)
{
    cout<<endl;
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}

// partition method of quick sort
void rearrange(int arr[], int n)
{
    int j=0;
    for(int i=0; i<n; i++)
    {
        if(arr[i] < 0)
        {
            if(i != j)
                swap(arr[i],arr[j]);
            j++;
            //cout<<"i = "<<i<<" j = "<<j;
            printArray(arr, n);
        }
    }
}
// using two pointer approach
void rearrange2(int arr[], int n)
{
    int lo = 0, hi = n-1;
    while(lo <= hi)
    {
        if(arr[lo] < 0 && arr[hi] < 0)
        {
            lo++;
        }
        else if(arr[lo] > 0 && arr[hi] < 0)
        {
            swap(arr[lo],arr[hi]);
            lo++; hi--;
        }
        else if(arr[lo] > 0 && arr[hi] > 0)
        {
            hi--;
        }
        else
        {
            lo++; hi--;
        }
    }
}



// Driver code
int main()
{
	int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
	int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);
	rearrange2(arr, n);
	printArray(arr, n);
	return 0;
}
