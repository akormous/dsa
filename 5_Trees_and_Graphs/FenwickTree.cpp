#include<bits/stdc++.h>
using namespace std;

/*
FENWICK TREE / BINARY INDEXED TREE
*/

/*
TESTING FUNCTIONS
*/
int getSumManual(vector<int> arr, int x) {
    int sum = 0;
    for(int i = 0; i <= x; i++)
        sum += arr[i];
    return sum;
}

// updates BITree given index and val, arr[index] += val
void update(vector<int> &BITree, int index, int val) {
    // set current index to index + 1
    int currentIndex = index + 1;
    // do the follwing till currentIndex is less than the size of arr
    // size of BITree = size of arr + 1
    while(currentIndex < BITree.size()) {
        // update the val at current index
        BITree[currentIndex] += val;
        // move to the next element
        currentIndex = currentIndex + (currentIndex & (-currentIndex));
    }
}

// function that takes in an array of n numbers,
// return an array of size n + 1, representing a fenwick tree
vector<int> createFenwickTree(vector<int> arr) {
    int n = arr.size();
    // create an array of size n+1 and initialize all elements to 0
    vector<int> BITree(n + 1, 0);

    // 0th index in fenwick tree is dummy index
    // traverse through the array and update BITree
    for(int i = 0; i < n; i++) {
        // update the value in BITree
        update(BITree, i, arr[i]);
    }

    return BITree;
}

// returns the sum of subarray arr[0 ... x] (inclusive x)
int getSum(vector<int> BITree, int x) {
    int sum = 0;
    int currentIndex = x + 1;

    while(currentIndex > 0) {
        // add the val of the currentIndex to sum
        sum += BITree[currentIndex];
        // go to the parent of currentIndex
        currentIndex = currentIndex - (currentIndex & (-currentIndex));
    }
    return sum;
}

int main() {
    // solution
    vector<int> arr = {12, 23, 35, 774, 75, 56, 27, 83, 95, 10, 234, 66, 542};

    // creating Binary Indexed tree
    vector<int> BITree = createFenwickTree(arr);

    cout<<"getSum from BITree\t "<<getSum(BITree, 5)<<endl;

    cout<<"getSum manual\t\t "<<getSumManual(arr, 5)<<endl;
    return 0;
}