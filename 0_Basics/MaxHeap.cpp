#include<bits/stdc++.h>
using namespace std;
/*

Max Heap
The maximum element is at the top of the heap

Left and right child are always less than the parent

*/

class MaxHeap {
    int* heapArr;   // heap array
    int capacity;   // max capacity of heap
    int heapSize;   // current size of the heap

    public:
    // Parameterized constructor
    MaxHeap(int c) {
        capacity = c;
        heapSize = 0;
        heapArr = new int[capacity];
    }
    // get left child index
    int left(int i) {
        return 2 * i + 1;
    }
    // get right child index
    int right(int i) {
        return 2 * i + 2;
    }
    // get parent index
    int parent(int i) {
        return (i - 1) / 2;
    }
    // get the maximum element from the heap - aka root
    int getMax() {
        return heapArr[0];
    }
    // heapify - top to bottom - fix the max heap property from a given index i
    void maxHeapify(int i) {
        int l = left(i);
        int r = right(i);
        // assume the parent to be the largest initially
        int largest = i;

        // if the left index is valid and greater than the parent
        if(l < heapSize && heapArr[l] > heapArr[largest])
            largest = l;
        
        // if the right index is valid and greater than largest
        if(r < heapSize && heapArr[r] > heapArr[largest])
            largest = r;
        
        // if mismatch was detected in the heap, then swap the largest element with the parent
        if(largest != i) {
            swap(heapArr[i], heapArr[largest]);
            // heapify the affected subtree
            maxHeapify(largest);
        }
    }

    // fixify - bottom to up - fix the max heap property from a given index i
    void maxFixify(int i) {
        // check if the parent is smaller than i, then replace it with parent
        while(i > 0 && heapArr[parent(i)] < heapArr[i]) {
            swap(heapArr[parent(i)], heapArr[i]);
            i = parent(i);
        }
    }

    // insert an element
    void insert(int val) {
        if(heapSize >= capacity) {
            return ;
        }
        // increase the heapSize
        heapSize++;
        int i = heapSize - 1;
        heapArr[i] = val;

        // fix the max heap property - bottom to top
        maxFixify(i);
    }
    // extract the maximum element
    int extractMax() {
        if(heapSize == 0) {
            return INT_MIN;
        }
        if(heapSize == 1) {
            heapSize--;
            return heapArr[0];
        }
        // the 0th element is the max
        int res = heapArr[0];

        // put the bottomost rightmost element at the root
        // the bottomost rightmost element will be at the end of the arr
        // aka at heapSize - 1;
        heapArr[0] = heapArr[heapSize - 1];
        // decrease the size of the heap
        heapSize--;

        // heapify from root
        // so it will go to its apt location
        maxHeapify(0);

        return res;
    }

    
    // delete an element from a given index
    void deleteKey(int i) {
        if(i < 0 || i >= heapSize) {
            return;
        }
        // assign the value at index i to INT_MAX
        heapArr[i] = INT_MAX;
        // swap the root with this element
        swap(heapArr[0], heapArr[i]);

        // fix the heap
        maxFixify(i);

        // extract the root
        extractMax();
    }

    // print the heap
    void print() {
        for(int i = 0; i < heapSize; i++) {
            cout<<i<<"\t"<<heapArr[i]<<endl;
        }
        cout<<endl;
    }
};

int main() {
    MaxHeap h(30);

    h.insert(3);
    h.insert(2);
    h.insert(1);
    h.insert(15);
    h.insert(5);
    h.insert(4);
    h.insert(45);
    h.insert(34);
    h.insert(12);
    h.insert(89);
    h.insert(190);
    h.insert(-54);
    h.insert(-980);
    h.insert(-222);


    h.print();

    cout<<"Maximum Element extract = "<<h.extractMax()<<endl;
    cout<<"Maximum Element extract = "<<h.extractMax()<<endl;
    cout<<"Maximum Element extract = "<<h.extractMax()<<endl;
    cout<<"Maximum Element extract = "<<h.extractMax()<<endl;
    
    h.print();
    
    cout<<"Current min element = "<<h.getMax()<<endl;

    cout<<"Deleting element at index 5"<<endl;
    h.deleteKey(5);

    h.print();



    return 0;
}