# Concurrency
Concurrency occurs when multiple copies of a program run simultaneously while communicating with each other.
A process can be executed by multiple different threads.

## Issues with concurrency
If you write multithreading programs like a crackhead, you can run into problems such as:

**Data Race**
- When two, or more threads in a single process access the same memory location concurrently
- at least one of the accesses is for writing
- the threads are not using any exclusive locks to control their accesses to that memory

When three of these conditions hold, the order of accesses is non-deterministic

**Race Condition**

A race condition occurs when two or more threads can access shared data and they try to change it at the same time. Because the thread scheduling algorithm can swap threads at any time, you don't know the order in which the threads will attempt to access the shared data.

## Concurrency vs Parallelism
**Parallelism** - multiple copies of the same program run simultaneously, but they are executed on different data

**Concurrency** - involves a shared memory location, and the different threads actually *read* the information provided by the previous threads

## Terminologies
<details>
    <summary>Thread Pool</summary>

- collection of worker threads that efficiently execute asynchronous callbacks on behalf of the application
- It is primarily used to reduce the number of application threads and provide management of worker threads
- Application can queue work items, associate work with waitable handles, automatically queue based on a timer, and bind with I/O

**Which applications can benefit from thread pool?**
- highly parallel applications that dispatch a large number of small work items asynchronously
- applications that create a large number of threads that each run for a short time
- applicaitons that require parallel processing (web browsers i.e. opening multiple tabs)

</details>

<details>
    <summary>Semaphores</summary>

- It is a non-negative variable and shared between threads
- It is used in thread synchronization and solving the critical section problem
- Semaphores are of 2 types:
    - **Binary Semaphore** - aka **Mutex lock**, it can have only 2 values (0 or 1)
    - **Counting Semaphore** - its value can range over an unrestricted domain, it is used to control access to a resource that has multiple instances
</details>

---

## C++ Syntax - Parallelism and Concurrency

### std::thread
`std::thread` is used to create an execution thread instance

```cpp
#include<iostream>
#include<thread>

int main() {
    std::thread t([](){
        std::cout << "hello world" << std::endl;
    })
    // join a thread i.e. blocks the calling thread until the thread whose join method is called has completed
    t.join();
    return 0;
}
```

### Mutex and Critical Section

Create a mutex by instantiating `std::mutex`

Member functions - `lock()` and `unlock()`. Instead of using lock and unlock for every mutex, you can use a `lock_guard()` which bounds the lifetime of the mutex lock to the lifetime of the object ([RAII](https://en.cppreference.com/w/cpp/language/raii))

Moreover, `unique_lock` is more flexible than `lock_guard`

`unique_lock` manages the locking and unlocking on a mutex object with exclusive ownership (no other `unique_lock` objects owning the ownership of a mutex). So, it is recommended to use `unique_lock` in concurrent programming. Below example uses `unique_lock`

Code: [Mutex Basics](../9_Concurrency/MutexBasics.cpp)