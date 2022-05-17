#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> visited;
    bool util(vector<int>& arr, int start, vector<bool>& visited)  {
        if(start < 0 || start >= arr.size())    return false;   // out of bounds
        if(arr[start] == 0)     return true;    // found zero
        if(arr[start] != 0 && visited[start] == true)   return false;   // visited ndoe
        
        visited[start] = true;  // visit the current node
        
        return util(arr, start - arr[start], visited) ||    // call for left and right
                util(arr, start + arr[start], visited);
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        return util(arr, start, visited);
    }
};