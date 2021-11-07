#include<bits/stdc++.h>
using namespace std;

/*

Question: Given a real number between 0 and 1, Convert it into binary string.


*/

int getWholePart(double num) {
    return int(num);
}

string realToBinary(double num) {
    string result = ".";
    while(num != 0) {
        if(result.length() > 32)
            return "ERROR";
        num = num * 2;
        result += to_string(getWholePart(num));
        num = num - getWholePart(num);
    }
    return result;
}



int main() {

    cout<<realToBinary(0.625)<<endl;
    return 0;
}