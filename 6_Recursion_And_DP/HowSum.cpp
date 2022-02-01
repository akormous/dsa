#include<bits/stdc++.h>
#include<chrono>
using namespace std;

void printArr(vector<int> v) {
    for(auto i : v)
        cout << i << " ";
}


/*
Given an array of numbers and a target sum, return an array of numbers
which add up to the target sum

Similar to Can Sum problem but here we have to return the array as well
instead of just a true or false value.
*/

/*
    RECURSIVE SOLUTION
    TC: O(n^m * m)
    SC: O(m)
*/
vector<int> howSumRecursion(int targetSum, vector<int> nums, vector<int>& arr) {
    if( targetSum == 0 )    return arr;

    if( targetSum < 0 )     return {};

    for(auto num : nums) {
        arr.push_back(num);

        if( !howSumRecursion(targetSum - num, nums, arr).empty())
            return arr;
        
        arr.pop_back();
    }
    return {};
}

/*
    MEMOIZATION SOLUTION
    TC: O(n*m*m)
    SC: O(m*m)
*/
vector<int> howSumMemo(int targetSum, vector<int> nums, vector<int>& arr, unordered_map<int,vector<int>>& memo) {
    if(memo.find(targetSum) != memo.end())  return memo[targetSum];

    if( targetSum == 0 )    return arr;

    if( targetSum < 0 )     return {};

    for(auto num : nums) {
        arr.push_back(num);

        if( !howSumMemo(targetSum - num, nums, arr, memo).empty()) {
            memo[targetSum] = arr;
            return memo[targetSum];
        }
            
        
        arr.pop_back();
    }
    memo[targetSum] = {};
    return {};
}

/*
    TABULATION SOLUTION
    TC: O()
    SC: O()
*/
vector<int> howSumTabulation(int targetSum, vector<int> nums) {
    // Initialize a table of size targetSum + 1
    // this table will store arrays of numbers, so choose the DS wisely
    // initially all of the arrays contain -1, 
    // -1 represents that the targetSum is not acheivable
    vector<vector<int>> table(targetSum + 1, vector<int>(targetSum + 1, {-1}));

    // 0 sum is acheivable by not taking anything
    table[0].clear();

    // for each targetSum, 
    for(int i = 0; i <= targetSum; ++i) {

        // if current targetSum is acheivable
        if( table[i].empty() || table[i][0] != -1) {
            
            // for each nums available
            for(auto num : nums) {

                // current target + num is acheivable
                if(i + num <= targetSum) {
                    // copy the array
                    table[i + num] = table[i];
                    // add num to the array
                    table[i + num].push_back(num);
                }
            }

        }
    }
    if(table[targetSum][0] != -1)
        return table[targetSum];

    return {};
}
int main() {
    
    cout << "RECURSION\n";
    auto start = chrono::high_resolution_clock::now();
    std::cout << "---------------------------------------\n";
    

    vector<int> result;
    if( !howSumRecursion( 300, {7,14}, result).empty()) {
        cout << "SUCCESS" << endl;
        printArr(result);
    }
    else {
        cout << "FAILURE" << endl;
    }
        
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    std::cout << "\nExecution Time: " << duration.count() << std::endl;
    std::cout << "---------------------------------------\n";
    
    
    cout << "MEMOIZATION\n";
    start = chrono::high_resolution_clock::now();
    std::cout << "---------------------------------------\n";
    
    
    result.clear();
    unordered_map<int,vector<int>> memo;
    if(!howSumMemo( 300, {7,14}, result, memo).empty()) {
        cout << "SUCCESS" << endl;
        printArr(result);
    }
    else {
        cout << "FAILURE" << endl;
    }
    
        
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    std::cout << "\nExecution Time: " << duration.count() << std::endl;
    std::cout << "---------------------------------------\n";
    
    cout << "TABULATION\n";
    start = chrono::high_resolution_clock::now();
    std::cout << "---------------------------------------\n";
    
    
    result.clear();
    result = howSumTabulation( 300, {7,14});
    if(!result.empty()) {
        cout << "SUCCESS" << endl;
        printArr(result);
    }
    else {
        cout << "FAILURE" << endl;
    }
    
        
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    std::cout << "\nExecution Time: " << duration.count() << std::endl;
    std::cout << "---------------------------------------\n";
    return 0;
}