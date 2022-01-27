#include<bits/stdc++.h>
#include<chrono>

using namespace std;

/*
Find number of ways to reach from top-left to bottom-right in a grid
*/

// returns the number of ways to reach from top-left to bottom-right
// in a m x n grid (m = rows, n = column)
int findNumberOfWaysRecursive(int m, int n) {
    if(m == 0 || n == 0)    return 0;
    if(m == 1 && n == 1)    return 1;

    return findNumberOfWaysRecursive(m-1, n)
         + findNumberOfWaysRecursive(m, n-1);
}

// Memoization
int findNumberOfWaysDP(int m, int n, unordered_map<string, int>& cache) {
    /* create a key*/
    string key = to_string(m) + "," + to_string(n);

    /* check in the cache if the value to the key is present */
    if(cache.find(key) != cache.end())  return cache[key];

    /* base cases */
    if(m == 0 || n == 0)    return 0;
    if(m == 1 && n == 1)    return 1;

    /* store in cache */
    cache[key] = findNumberOfWaysDP(m-1, n, cache)
         + findNumberOfWaysDP(m, n-1, cache);

    return cache[key];
}

// Tabulation
int findNumberOfWaysDP2(int m, int n, vector<vector<int>>& table) {
    
    // for a grid[1][1], there is only one way
    table[1][1] = 1;
        
    for(int row = 0; row <= m; ++row) {
        for(int col = 0; col <= n; ++col) {

            int cur = table[row][col];

            // add this current value to the right neighbor and down neighbor,
            // if they are in range
            // if right neighbor is in range
            if(col + 1 <= n)
                table[row][col+1] += cur;

            // if down neighbor is in range
            if(row + 1 <= m)
                table[row+1][col] += cur;
        }
    }
    
    return table[m][n];
}

int main() {
    auto start = chrono::high_resolution_clock::now();

    // Brute force - Recursive
    int m = 13;
    int n = 13;
    //cout<< m << "x" << n << " grid = " << findNumberOfWaysRecursive(m, n)<<endl;
    
    // Memoization
    // Implement a cache which will map "m,n" string to its value
    unordered_map<string, int> cache;
    //cout<< m << "x" << n << " grid = " << findNumberOfWaysDP(m, n, cache) << endl;


    // Tabulation
    // Implement a table like structure which will store the solutions in a bottom-up manner
    vector<vector<int>> table(m+1, vector<int>(n+1, 0));
    cout<< m << "x" << n << " grid = " << findNumberOfWaysDP2(m, n, table)<<endl;



    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "\nExecution time: " << duration.count() <<" ms" << endl;
    return 0;

}