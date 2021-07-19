#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Sorting the intervals according to the start element in the pair
        sort(intervals.begin(), intervals.end());
        // Creating a stack, where intervals will be pushed
        stack<vector<int>> s;
        // pushing the first interval in the stack
        s.push(intervals[0]);
        
        // iterating over all the intervals
        int n = intervals.size();
        for(int i=1; i < n; i++)
        {
            // checking if the most recently pushed interval is overlapping with the current one
            vector<int> top = s.top();
            if( intervals[i][0] <= top[1] && 
                intervals[i][0] >= top[0] )
            {
                top[1] = max(top[1], intervals[i][1]);
                s.pop();
                s.push(top);
            }
            else
            {
                s.push(intervals[i]);
            }
        }
        // creating the resulting vector
        vector<vector<int>> result;
        while(!s.empty())
        {
            vector<int> temp = s.top();
            s.pop();
            result.insert(result.begin(), temp);
        }
        return result;
    }
};