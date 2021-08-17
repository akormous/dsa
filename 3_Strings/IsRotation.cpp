#include<bits/stdc++.h>
using namespace std;

/*
Question - 
String Rotation: Assume you have a method isSubstring which checks if one word is a substring
of another. Given two strings, sl and s2, write code to check if s2 is a rotation of sl using only one
call to isSubstring (e.g., "waterbottle" is a rotation of"erbottlewat")


Input-
s1 = iamironman

s2 = ironmaniam


Approach - 

Split the string into two parts x and y
in the above example
x = iam
y = ironman

s1 = xy
s2 = yx

yx will always be there in xyxy

--------------------------------------
So, basically, we just need to search for s2 in s1s1
Apply, most efficient string searching algorithm
or in-built search function
--------------------------------------

If you observe carefully,
s2 will always be a substring of s1s1

where s1s1 = s1 + s1;


*/

bool isRotation(string s1, string s2) {
    // if unequal lengths
    if(s1.length() != s2.length() || s1.length() < 0)
        return false;
    
    string s1s1 = s1 + s1;
    // find s2 in s1s1
    return (s1s1.find(s2) != string::npos);
}

/*

NOTE: The in-build find function is not the most efficient
So, you need to implement KMP, if TLE occurs

*/


int main() {
    string s1 = "iamironman";
    string s2 = "ironmaniam";

    if(isRotation(s1,s2))
        cout<<"Yes";
    else
        cout<<"No";
    cout<<endl;

    if(isRotation(s2,s1))
        cout<<"Yes";
    else
        cout<<"No";
    cout<<endl;
    return 0;
}