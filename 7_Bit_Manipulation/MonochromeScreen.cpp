#include<bits/stdc++.h>
using namespace std;

/*

Draw Line: A monochrome screen is stored as a single array of bytes, allowing eight consecutive
pixels to be stored in one byte. The screen has width w, where w is divisible by 8 (that is, no byte will
be split across rows). The height of the screen, of course, can be derived from the length of the array
and the width. Implement a function that draws a horizontal line from ( xl, y) to ( x2, y).
The method signature should look something like:
drawline(byte[] screen, int width, int xl, int x2, int y)


Calculate height = screen.size() / width

The line height is constant, so only a horizontal line is to be drawn.
I am assuming that the coordinates mentioned are inclusive in the line.

Drawing a horizontal line = flipping all bits falling on that line to 0 or 1

Ensure x1 and x2 lie within the width of the screen

The main idea is to map pixel rows on the screen to 1-Dimensional array given in the question.

screen[
    1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,    
]

y = 3
x1 = 2, x2 = 7

screen[
    1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,
    1,1,0,0,0,0,0,0,
    1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,    
]

Step 1: From what index in the 1D array should I start counting the x1 coords = 8*(y-1)
cursor = 8*(y - 1)

Step 2: Start counting till you reach x1
for(int i = 0; i < x1; i++)
    cursor++;

Step 3: Start painting the pixels one-by-one till x2
for(int i = x1; i <= x2; i++) {
    screen[cursor] = 0;
    cursor++;
}

Step 4: Youre done bro
*/

int getHeight(int area, int width) {
    return area / width;
}

void drawline(vector<bool> &screen, int width, int x1, int x2, int y) {
    int height = getHeight(screen.size(), width);

    int cursor = 0;
    // navigate to the desired row
    cursor = width*(y - 1);

    // reach x1
    for(int i = 0; i < x1; i++) {
        cursor++;
    }

    // start painting the pixels one-by-one till x2
    for(int i = x1; i <= x2; ++i) {
        screen[cursor] = 1;
        cursor++;
    }
}

void displayScreen(vector<bool> screen, int w) {
    int h = getHeight(screen.size(), w);

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; ++j)
            cout<<screen[(8*i) + j]<<" ";
        cout<<endl;
    }
}

int main() {
    // solution
    // an 8 by 8 screen size
    vector<bool> screen(64);
    fill(screen.begin(), screen.end(), 0);
    int w = 8;
    displayScreen(screen, w);
    cout<<endl;
    drawline(screen, w, 2, 7, 3);
    displayScreen(screen, w);

    return 0;
}