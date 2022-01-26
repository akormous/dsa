#include<bits/stdc++.h>
#include<chrono>
using namespace std;

/*
Given an array of numbers, and a target sum,
check whether the target sum can be acheived from the given set of numbers
*/

/*
BRUTE FORCE
Time Complexity: O(n^m) where n is the size of the arr and m is the targetSum
Space Complexity: O(m) as the maximum height of the recursion tree can be m (worst case when the arr contains 1)
*/
bool canSumRecursion(vector<int> arr, int targetSum) {
    if(targetSum < 0)   return false;
    if(targetSum == 0)  return true;

    for(int i = 0; i < arr.size(); ++i) {
        if(canSumRecursion(arr, targetSum - arr[i]))
            return true;
    }
    return false;
}

/*
MEMOIZATION
Time Complexity: O(m*n) because of memo
Space Complexity: O(m)
*/
bool canSumMemo(vector<int> arr, int targetSum, unordered_map<int, bool>& memo) {
    // if already in the memo
    if(memo.find(targetSum) != memo.end())
        return memo[targetSum];

    if(targetSum < 0)   return false;
    if(targetSum == 0)  return true;

    for(int i = 0; i < arr.size(); ++i) {
        if(canSumRecursion(arr, targetSum - arr[i])) {
            memo[targetSum] = true;
            return true;
        }
            
    }
    memo[targetSum] = false;
    return false;
}

/*
TABULATION
Time Complexity: 
Space Complexity: 
*/
void recursion() {
    auto start = chrono::high_resolution_clock::now();
    std::cout << "---------------------------------------\n";


    /*	FUNCTION CODE HERE
    */
    if( canSumRecursion({7,14}, 243) )
        cout<<"YES";
    else
        cout<<"NO";


    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    std::cout << "\nExecution Time: " << duration.count() << std::endl;
    std::cout << "---------------------------------------\n";
    return ;
}

void memoization() {
    auto start = chrono::high_resolution_clock::now();
    std::cout << "---------------------------------------\n";


    /*	FUNCTION CODE HERE
    */
    unordered_map<int,bool> memo;
    if( canSumMemo({7,14}, 243, memo) )
        cout<<"YES";
    else
        cout<<"NO";


    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    std::cout << "\nExecution Time: " << duration.count() << std::endl;
    std::cout << "---------------------------------------\n";
    return ;
}

int main() {
    // solution
    
    recursion();

    //memoization();


    return 0;
}