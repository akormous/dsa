#include<bits/stdc++.h>
using namespace std;

/*

You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 2^31 - 1 = INT_MAX to represent INF as you may assume that the distance to a gate is less than INT_MAX.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a Gate, that room should remain filled with INF

*/
class Solution {
public:
    /**
     * @param rooms: m x n 2D grid
     * @return: nothing
     */
    void putDistToRooms(vector<vector<int>>& rooms, int& m, int& n, int i, int j) {
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,-1,1};

        // BFS
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int rr = r + dx[i];
                int cc = c + dy[i];
                if(rr < 0 or rr >= m or cc < 0 or cc >= n or rooms[rr][cc] == -1 or rooms[rr][cc] < rooms[r][c] + 1) continue;

                rooms[rr][cc] = min(rooms[rr][cc], rooms[r][c] + 1);
                q.push({rr,cc});
            }
        }
    }
    void wallsAndGates(vector<vector<int>> &rooms) {
        // BFS at every empty room
        int m = rooms.size(), n = rooms[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(rooms[i][j] == -1 or rooms[i][j] == INT_MAX)
                    continue;
                // do a BFS at every 0, and update the dist to every room encountered
                putDistToRooms(rooms, m, n, i, j);
            }
        }
    }
};

int main() {
    vector<vector<int>> rooms = {
        {INT_MAX,-1,0,INT_MAX},
        {INT_MAX,INT_MAX,INT_MAX,-1},
        {INT_MAX,-1,INT_MAX,-1},
        {0,-1,INT_MAX,INT_MAX}
    };
    Solution s;
    s.wallsAndGates(rooms);

    for(auto& r : rooms) {
        for(auto& c : r)
            cout << c << " " ;
        cout << endl;
    }
    return 0;
}