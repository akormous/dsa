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
bool canSumTabulation(vector<int> arr, int targetSum) {
    // create a boolean table/1D array in this case of size targetSum
    bool dp[targetSum + 1];
    // initialize all values to false
    memset(dp, 0, sizeof(dp));

    
    // there is always a way to make 0 sum (dont take anything from the set of numbers)
    dp[0] = true;
    
    // start from 0 till targetSum
    for(int i = 0; i <= targetSum; ++i) {
        // if i can make the current sum,
        if(dp[i] == true) {
            // then it is possible to make currentSum + arr[j] where j = 0 to arr.size()

            for(auto j : arr) {
                if(i + j <= targetSum)
                    dp[i + j] = true;
            }
        }

        if(dp[targetSum] == true)
            return true;
    }
    return false;
}

void recursion() {
    auto start = chrono::high_resolution_clock::now();
    std::cout << "---------------------------------------\n";
    
    cout<<"\nRecursion\n";

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

    cout<<"\nMemoization\n";
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

void tabulation() {
    auto start = chrono::high_resolution_clock::now();
    std::cout << "---------------------------------------\n";

    cout<<"\nTabulation\n";
    /*	FUNCTION CODE HERE
    */
    if( canSumTabulation({7,14}, 243) )
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
    tabulation();

    //memoization();


    return 0;
}