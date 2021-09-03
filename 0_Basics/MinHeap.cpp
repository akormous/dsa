#include<bits/stdc++.h>
using namespace std;

/*

Min-Heap:
The smallest element is at the root

How is Binary Heap represented ?
Heaps are represented using an array.
Because they are complete binary tree, using array is very efficient
as it will be densely filled


Left Child node - 2*i + 1
Right Child node - 2*i + 2
Parent node - ( i - 1 )/ 2

where i is the index

The traversal method used to acheive the array is level order traversal
*/

class MinHeap {
    
    int* heapArr;   // Heap Array
    int capacity;   // How many elements can the heap contain
    int heapSize;   // Current number of elements in the heap

    public:

    // Parameterized Constructor
    MinHeap(int cap) {
        capacity = cap;
        heapArr = new int[capacity];
        heapSize = 0;
    }

    // return left child index
    int left(int i) {
        return 2 * i + 1;
    }

    // return right child index
    int right(int i) {
        return 2 * i + 2;
    }

    // return parent node index
    int parent(int i) {
        if(i == 0) {
            cout<<"Root doesn't have any parent"<<endl;
            return 0;
        }
        return ( i - 1 )/ 2;
    }

    // get the minimum element from the heap
    int getMin() {
        return heapArr[0];
    }

    // Fix the heap property of the subtree
    // the root of the subtree is passed as parameter
    // NOTE: Heapify kind of works in a top-down approach
    void minHeapify(int i) {
        // get the left index
        int l = left(i);
        // get the right index
        int r = right(i);

        // assume the root element as smallest
        int smallest = i;

        // if left index is valid 
        // and if left is smaller than root
        if(l < heapSize && heapArr[l] < heapArr[smallest])
            smallest = l;
        
        // if right index is valid 
        // and right is smaller than the smaller number established above
        if(r < heapSize && heapArr[r] < heapArr[smallest])
            smallest = r;
        
        // if the minHeap property was violated
        if(smallest != i) {
            swap(heapArr[i], heapArr[smallest]);
            // heapify the affected subtree
            minHeapify(smallest);
        }
    }

    // Fixify works in a bottom-up approach, aka swapping the parents
    void minFixify(int i) {
        // fix the heap property
        while(i > 0 && heapArr[parent(i)] > heapArr[i]) {
            swap(heapArr[parent(i)], heapArr[i]);
            i = parent(i);
        }
    }

    // extract the minimum element from the heap
    int extractMin() {
        if(heapSize <= 0) {
            return INT_MAX;
        }
        if(heapSize == 1) {
            heapSize--;
            return heapArr[0];
        }

        int min = heapArr[0];
        // put the bottomost rightmost element at the root
        heapArr[0] = heapArr[heapSize - 1];

        // decrease the heap size
        heapSize--;

        // minHeapify from root
        minHeapify(0);

        
        return min;
    }

    // insert a new element in the heap with value val
    void insert(int val) {
        if(heapSize >= capacity) {
            cout<<"Heap is completely filled! Cannot insert more elements"<<endl;
            return;
        }
        // insert at the bottomost rightmost position in the heap
        heapSize++;
        int i = heapSize - 1;
        heapArr[i] = val;

        minFixify(i);
    }

    // delete an element from the heap at index i
    void deleteKey(int i) {
        if(i < 0 || i > heapSize) {
            cout<<"Invalid Index"<<endl;
            return;
        }
        // assign the val at i to INT_MIN
        heapArr[i] = INT_MIN;

        // fix the heap property
        minFixify(i);
        
        // Now the element will reach at the top, so just
        // extract the root (aka min element)
        extractMin();

    }

    void print() {
        
        for(int i = 0; i < heapSize; i++) {
            cout<<i<<"\t"<<heapArr[i]<<endl;
        }
        cout<<endl;
    }

};

int main() {
    MinHeap h(30);

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

    cout<<"Minimum Element extract = "<<h.extractMin()<<endl;
    cout<<"Minimum Element extract = "<<h.extractMin()<<endl;
    cout<<"Minimum Element extract = "<<h.extractMin()<<endl;
    cout<<"Minimum Element extract = "<<h.extractMin()<<endl;
    
    h.print();
    
    cout<<"Current min element = "<<h.getMin()<<endl;

    cout<<"Deleting element at index 5"<<endl;
    h.deleteKey(5);

    h.print();


    return 0;
}