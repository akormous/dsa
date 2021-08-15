#include<bits/stdc++.h>
using namespace std;

/*
Question - 
Rotate Matrix: Given an image represented by an NxN matrix, where each pixel in the image is 4
bytes, write a method to rotate the image by 90 degrees. Can you do this in place?

Basically rotate a matrix by 90 degrees, in place.

Consider rotating anti-clockwise
NOTE: the matrix is square

Aprroach - 
Input
1 2 3
4 5 6
7 8 9

Output
3 6 9
2 5 8
1 4 7

Input
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

Output
4 8 12 16
3 7 11 15
2 6 10 14
1 5 9 13

Input 
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25

Output
5 10 15 20 25
4 9 14 19 24
3 8 13 18 23
2 7 12 17 22
1 6 11 16 21

-> Swap the elements in a circular fashion, layer by layer
When to stop > N/2 ?


*/

void rotateMatrix(vector<vector<int>> &m) {
    int n = m[0].size();
    // max layers that are possible
    int maxLayers = n/2;
    // go in a layerwise fashion and rotate the elements
    int layer = 0;
    while(layer < maxLayers) {
        for(int i = layer; i < n - 1 - layer; i++) {
            int temp = m[layer][i];
            
            m[layer][i] = m[i][n - 1 - layer];

            m[i][n - 1 - layer] = m[n - 1 - layer][n - 1 - i];

            m[n - 1 - layer][n - 1 - i] = m[n - 1 - i][layer];

            m[n - 1 - i][layer] = temp;
        }
        layer++;
    }

}

void displayMatrix(vector<vector<int>> m) {
    int n = m[0].size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout<<m[i][j]<<" ";
        cout<<endl;
    }
    return ;
}

vector<vector<int>> inputMatrix() {
    int n;
    cout<<"Enter value of n ";
    cin>>n;
    cout<<"Enter n*n numbers"<<endl;
    vector<vector<int>> m(n, vector<int> (n, 0));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin>>m[i][j];
    return m;
}

int main() {
    // solution
    vector<vector<int>> m = inputMatrix();
    cout<<endl;
    rotateMatrix(m);
    cout<<endl;
    displayMatrix(m);
    return 0;
}