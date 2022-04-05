#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        
        int maxArea = INT_MIN;
        
        while(l <= r) {
            
            int areaCovered = (r-l) * (min(height[l],height[r]));
            maxArea = max(maxArea, areaCovered);
            
            if(height[l] < height[r])
                l++;
            else
                r--;
        }
        return maxArea;
    }
};