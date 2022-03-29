#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isOutOfBounds(int i, int j, int m, int n) {
        if(i < 0 || i >= m || j < 0 || j >= n)  return true;
        return false;
    }
    
    
    void fillPaint(vector<vector<int>>& image, int i, int j, int m, int n, int oldColor, int newColor) {
        
        if(isOutOfBounds(i, j, m, n))  return;
        
        if(image[i][j] != oldColor) return;
        
        image[i][j] = newColor;
        
        fillPaint(image, i+1, j, m, n, oldColor, newColor);
        fillPaint(image, i-1, j, m, n, oldColor, newColor);
        fillPaint(image, i, j+1, m, n, oldColor, newColor);
        fillPaint(image, i, j-1, m, n, oldColor, newColor);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
        int oldColor = image[sr][sc];
        
        if(oldColor == newColor)
            return image;
        
        fillPaint(image, sr, sc, m, n, oldColor, newColor);
        
        return image;
    }
};