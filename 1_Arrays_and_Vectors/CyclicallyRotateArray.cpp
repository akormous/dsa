// { Driver Code Starts
//Initial Template for C++

#include <stdio.h>

void rotate(int arr[], int n);

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n] , i;
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        rotate(a, n);
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
        return 0;
}
// } Driver Code Ends


//User function Template for C++
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void rotate(int arr[], int n)
{
    int i=0, j=n-1;
    while(i != j)
    {
        swap(arr[i],arr[j]);
        i++;
    }
}