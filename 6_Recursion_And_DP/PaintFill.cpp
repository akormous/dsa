/*

Paint Fill: Implement the "paint fill" function that one might see on many image editing programs.
That is, given a screen (represented by a two-dimensional array of colors), a point, and a new color,
fill in the surrounding area until the color changes from the original color.

*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    void fillDFS(vector<vector<int>>& image, int sr, int sc, int newColor, int oldColor) {
        // if pixel is out of bounds
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size())
            return;
        
        // if the current pixel is not the old color
        if(image[sr][sc] != oldColor)
            return;
        
        image[sr][sc] = newColor;
        
        fillDFS(image, sr+1, sc, newColor, oldColor);
        fillDFS(image, sr, sc+1, newColor, oldColor);
        fillDFS(image, sr-1, sc, newColor, oldColor);
        fillDFS(image, sr, sc-1, newColor, oldColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        if(newColor == image[sr][sc])   return image;
        if(image.size() == 0)   return image;
        
        fillDFS(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends