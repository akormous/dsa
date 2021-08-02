/*
Find median of two sorted arrays of different size
Watch this -
https://www.youtube.com/watch?v=NTop3VTjmxk&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=66
*/
#include<bits/stdc++.h>
using namespace std;

// a bunch of helper function to calculate medians


/* Returns median of a sorted array */
float getMedian(int arr[], int s) {
    if(s == 0)
        return -1;
    if(s&1)
        return arr[s/2];
    return ( arr[s/2] + arr[s/2 - 1] ) / 2.0;
}


float getCombinedMedian(int a[], int b[], int n, int m) {
    int low = 0, high = n;

    while(low <= high) {
        int cut1 = (low+high) / 2;
        int cut2 = (n + m + 1) / 2 - cut1;

        int left1 = cut1 == 0 ? INT_MIN : a[cut1 - 1];
        int left2 = cut2 == 0 ? INT_MIN : b[cut2 - 1];

        int right1 = cut1 == n ? INT_MAX : a[cut1];
        int right2 = cut2 == m ? INT_MAX : b[cut2];

        if(left1 <= right2 && left2 <= right1) {
            if((n+m)%2 == 0)
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            else
                return max(left1, left2);
        }
        else if(left1 > right2)
            high = cut1 - 1;
        else
            low = cut1 + 1;
    }
    return 0.0;
}

// verify the result
float chadMedian(int a[], int b[], int n, int m) {
    // merging the arrays
    int s = n + m;
    int c[s];
    int i = 0, j = 0, k = 0;
    while(i < n && j < m) {
        if(a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }

    // flushing in the remaining arrays
    while(i < n)
        c[k++] = a[i++];
    while(j < m)
        c[k++] = b[j++];

    return getMedian(c, s);
}



int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[] = {-10, -5, -4, -3, -2, -1, 0, 1, 11, 12, 13, 14, 15, 19, 21, 22, 23, 1001, 2000, 2004, 5000 };
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
    // always considering size of array a is less than that of b
    cout<<"Combined Median = "<<getCombinedMedian(a, b, n, m)<<endl;
    cout<<endl<<"Verified result = "<<chadMedian(a, b, n, m)<<endl;
    return 0;
}