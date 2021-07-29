/*
Given a 2D matrix, and coordinates for origin and destination
calculate the number of ways to reach destination from origin
with only some moves allowed (for ex. up and right, left and down, or all directions)
*/
#include<bits/stdc++.h>
using namespace std;

int reachDestination(vector<vector<int>> arr, int x, int y, pair<int,int> dest) {
    // check if we have reached the destination
    if(x == dest.first && y == dest.second) {
        return 1;
    }
    // check if cur coords are out of bounds or if the coords are already visited
    if(x < 0 || y > arr[0].size() || arr[x][y] == 1)
        return 0;

    // visit the coords
    arr[x][y] = 1;
    // move to right and up
    return reachDestination(arr, x - 1, y, dest) + reachDestination(arr, x, y + 1, dest);
}

// in the given matrix source is represented by -1
// and destination is represented by 1
int main() {
    vector<vector<int>> arr = {{0,  0, 0, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0}};
    pair<int,int> src = {3, 0};
    pair<int,int> dest = {0, 3};
    cout<<"Number of ways to reach destination = "<<reachDestination(arr, src.first, src.second, dest)<<endl;
    return 0;
}