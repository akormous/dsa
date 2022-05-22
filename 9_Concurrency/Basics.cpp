#include<thread>
#include<bits/stdc++.h>
#include<chrono>
using namespace std;

void sleepAndPrint(int iThreadId, int iSeconds, string iMsg) {
    this_thread::sleep_for(chrono::milliseconds(iSeconds*1000));
    cout << "------------------------------" << endl;
    cout << "Thread ID = " << iThreadId << endl;
    cout << "Sleep time = " << iSeconds << endl;
    cout << "Msg = " << iMsg << endl;
    cout << "------------------------------" << endl;
}

int main() {
    cout << "Hello from main" << endl;

    vector<string> messages = {
        "Hello World",
        "I am a programmer",
        "I also like to play video games",
        "My favorite game is Valorant"
    };

    vector<int> sleepTime = {7, 3, 5, 1};
    int id = 0;

    vector<thread> pool;

    for(string msg : messages) {
        pool.push_back(thread(sleepAndPrint, id++, sleepTime[id], msg));
    }

    for(thread& t : pool)
        t.join();
    return 0;
}