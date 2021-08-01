/*
Median of two sorted arrays of same size
What is median ?
The middle element in a sorted array
*/
#include<bits/stdc++.h>
using namespace std;

/*
Approach:
Step 1: Calculate median of both arrays, if they are equal then return it
Let median of first array be m1 and of second array be m2

Step 2: if(m1 > m2) {
    Then the combined median is present in one of these two subarrays
    a[0] ... a[m1_index]
    b[m2_index] .. b[m]
    
    and vice versa
Step 3: Repeat the above process until the size of both arrays becomes 2
If size of both arrays is 2, then median will be
    
    median = max(a[0], b[0]) + min(a[1], b[1]) / 2

    Since a and b are sorted, ya know
}

Time Complexity: O(log(n))

n = 5
1 12 13 15 19
2 14 16 17 20

n = 3
13 15 19
2 14 16

*/


int getMedian(int arr[], int s) {
    if(s&1)
        return arr[s/2];
    return ( arr[s/2] + arr[s/2 - 1] ) / 2;
}
int getCombinedMedian(int a[], int b[], int n) {
    // if n < 0
    if(n <= 0) {
        return -1;
    }
    if(n == 1) {
        return (a[0] + b[0]) / 2;
    }
    if(n == 2) {
        return ( max(a[0], b[0]) + min(a[1], b[1]) )/ 2;
    }
    // median of first array
    int m1 = getMedian(a, n);
    // median of second array
    int m2 = getMedian(b, n);

    // check if both medians are equal
    if(m1 == m2)
        return m1;
    // if median of first array < median of second array
    if(m1 < m2) {
        if( n%2 == 0 )
            return getCombinedMedian(a + n/2 - 1, b, n - n/2 + 1);
        return getCombinedMedian(a + n/2, b, n - n/2 );
    }
    // if median of second array < median of first array
    if(n%2 == 0)
        return getCombinedMedian(a, b + n/2 - 1, n - n/2 + 1);
    return getCombinedMedian(a, b + n/2, n - n/2);

}

int main() {
    // we have two sorted arrays
    int ar1[] = {1, 12, 15, 26, 38};
    int ar2[] = {2, 13, 17, 30, 45};
    int n = sizeof(ar1) / sizeof(ar1[0]);

    cout<<"Median of the 2 arrays = "<<getCombinedMedian(ar1, ar2, n)<<endl;

    return 0;
}