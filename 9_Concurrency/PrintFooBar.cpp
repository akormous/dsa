#include<thread>
#include<bits/stdc++.h>

using namespace std;

class Foo {
public:
    Foo() {
        lastExecutedFunction = 0;   // initially
    }

    void first(function<void()> printFirst) {
        unique_lock<mutex> lock(mtx);  // acquire lock
        cv.wait(lock, [&]{return lastExecutedFunction == 0;});  // wait until last executed function is 0, initial condition
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        
        lastExecutedFunction = 1;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [&]{return lastExecutedFunction == 1;});  // wait until last exec function is first()
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        
        lastExecutedFunction = 2;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [&]{return lastExecutedFunction == 2;});  // wait until last exec function is second()
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        
        lastExecutedFunction = 0;
        cv.notify_all();
    }
private:
    mutex mtx;
    condition_variable cv;
    int lastExecutedFunction;   // 0 (initial), 1, 2, or 3
};