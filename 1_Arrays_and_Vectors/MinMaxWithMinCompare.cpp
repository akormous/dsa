#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Pair {
    int max;
    int min;
};

Pair getMinMax(int arr[], int n)
{
    Pair minmax;
    int i=0;
    if(n%2 == 0)
    {
        if(arr[i] > arr[i+1])
        {
            minmax.max = arr[i];
            minmax.min = arr[i+1];
        }
        else
        {
            minmax.max = arr[i+1];
            minmax.min = arr[i];
        }
        i = 2;
    }
    else
    {
        minmax.max = arr[i];
        minmax.min = arr[i];
        i = 1;
    }
    while(i <= n-2)
    {
        if(arr[i] > arr[i+1])
        {
            if(arr[i] > minmax.max)
                minmax.max = arr[i];
            if(arr[i+1] < minmax.min)
                minmax.min = arr[i+1];
        }
        else
        {
            if(arr[i+1] > minmax.max)
                minmax.max = arr[i+1];
            if(arr[i] < minmax.min)
                minmax.min = arr[i];
        }
        i++;
    }
    return minmax;
}

int main()
{
    int arr[] = { 1000, -11, 445, 1, 330, -3000};
    int n = 6;
    Pair answer = getMinMax(arr, n);
    cout<<"Minimum element: "<<answer.min<<endl;
    cout<<"Maximum element: "<<answer.max<<endl;
    return 0;
}