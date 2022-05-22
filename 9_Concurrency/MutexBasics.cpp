#include<bits/stdc++.h>
#include<thread>

using namespace std;

int resource = 0;   // shared resource
static mutex mtx;

void critical_section(int iResource) {
    unique_lock<mutex> lock(mtx);
    resource = iResource;
}

int main() {
    thread t1(critical_section, 69);
    thread t2(critical_section, 420);
    t1.join();
    t2.join();

    cout << resource << endl;
}