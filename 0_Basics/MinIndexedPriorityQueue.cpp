#include<bits/stdc++.h>
using namespace std;

#define LOG(msg) cout << endl << msg << endl

/*

Definition:

An Indexed Priority Queue is a traditional priority queue variant
which on top of regular priority queue operations
supports quick updates and deletions of key-value pairs

IPQ is very important when the priority changes dynamically.

First step to using an IPQ is to 
assign key index values to all the keys,
forming a bidirectional mapping, means that keys map to key index, and key index map to keys
*/

/**
 * IPQ
*/
class MinIndexedPriorityQueue {
public:
    /**
     * IPQ Constructor
     * @param capacity - max capacity of IPQ
    */
    MinIndexedPriorityQueue(int capacity) {
        this->maxSize = capacity;
        size = 0;
        vals.resize(maxSize);   fill(vals.begin(), vals.end(), INT_MAX);
        pm.resize(maxSize);   fill(pm.begin(), pm.end(), -1);
        im.resize(maxSize);   fill(im.begin(), im.end(), -1);
    }
    MinIndexedPriorityQueue() = delete;
    /**
     * get size of the IPQ
    */
    int getSize() {
        return size;
    }

    /**
     * insert into IPQ
     * @param ki - key index
     * @param value - value
    */
    void insert(int ki, int value) {
        if( !isValidKey(ki) || contains(ki)) {
            LOG("INVALID KEY!");
            return;
        }
        // insert the key at the end of the heap array
        pm[ki] = size;
        im[size] = ki;
        
        // insert value
        vals[ki] = value;
        swim(size);
        size += 1;
    }
    /**
     * Poll - remove the root node
    */
    void poll() {
        int ki = im[0];
        if(!isValidKey(ki))
            return;
        remove(im[0]);
    }
    /**
     * Removing from the IPQ - removing the node with key index ki
     * @param ki - key index
    */
    void remove(int ki) {
        if( !contains(ki) ) {
            LOG("INVALID KEY!");
            return;
        }
        // store the heap index
        int i = pm[ki];
        // swap the given node with the bottomost right node
        swapNodes(i, size-1);
        // sink down in the heap
        sink(i);
        // swim up the heap
        swim(i);
        // delete the val
        vals[ki] = INT_MAX;
        pm[ki] = -1;
        im[size-1] = -1;
        // decrease the size
        size -= 1;
    }
    /**
     * update the value of a given key
     * @param ki key index of the node to be updated
     * @param value the updated value
    */
    void update(int ki, int value) {
        // get the heap index of the ki
        int i = pm[ki];
        // update the value in vals array
        vals[ki] = value;
        // either go down the heap
        sink(i);
        // or go up the heap
        swim(i);
    }
    /**
     * top - return the root value
    */
    int top() {
        int ki = im[0];
        return vals[ki];
    }

    void printAll() {
        cout<<endl << "INDEX\t";
        for(int i = 0; i < size; ++i)
            cout<<i<<"\t";
        cout<<endl<< "VALS\t";
        for(auto i : vals)
            cout<<i<<"\t";
        cout<<endl<< "PM\t";
        for(auto i : pm)
            cout<<i<<"\t";
        cout<<endl<< "IM\t";
        for(auto i : im)
            cout<<i<<"\t";
        cout<<endl;
    }

    void printHeap() {
        cout << endl;
        for(int i = 0; i < size; i++) 
            cout << vals[im[i]] << " ";

        cout<<endl;
    }
    
private:
    /**
     * returns parent index of given heap index
     * @param - heap index of a node
    */
    int getParent(int i) {
        return (i-1)/2;
    }
    /**
     * compares 2 nodes with heap indices a and b and 
     * returns true if vals[a] < vals[b]
     * @param a - heap index of 1st node
     * @param b - heap index of 2nd node
    */
    bool less(int a, int b) {
        return (vals[im[a]] < vals[im[b]]);
    }

    /**
     * swaps 2 nodes in the heap, also fixes the position map and inverse map
     * @param a - heap index of 1st node
     * @param b - heap index of 2nd node
    */
    void swapNodes(int a, int b) {
        pm[ im[a] ] = b;
        pm[ im[b] ] = a;
        //cout << "swapping "<<a << " " << b << endl;
        // temp = key index of b
        int temp = im[a];
        im[a] = im[b];
        im[b] = temp;
    }
    /**
     * swim up the heap, and fix heap property (the node swims up to its correct position in the heap)
     * since this is a min IPQ so the root of the heap should be minimum
     * @param - heap index i
    */
    void swim(int i) {
        // start comparing value of the current node with its parent and
        // keep on swapping till the heap property is satisfied
        //cout << "swimming " << i << " parent = " << getParent(i) << endl;
        while(less(i, getParent(i))) {
            swapNodes(i, getParent(i));
            i = getParent(i);
        }
    }
    /**
     * sink a node to its correct position in the heap
     * @param - heap index i
    */
    void sink(int i) {
        while(1) {
            // left child heap index
            int left = 2*i + 1;
            // right child heap index
            int right = 2*i + 2;
            // assume the left child to be the smallest
            int smallest = left;
            if(right < size && less(right, left))
                smallest = right;
            // if left is out of bounds OR if parent is the smallest among parent, left and right, then break from the loop            
            if(left >= size || less(i, smallest))
                break;
                        // else swap the parent with the smallest child
            swapNodes(i, smallest);
            i = smallest;
        }
    }
    /*
    HELPER FUNCTIONS - to make code more readable
    */
    bool contains(int key) {
        return pm[key] != -1;
    }

    bool isValidKey(int key) {
        return (key >= 0 && key < maxSize);
    }
    /**
     * size -> size of IPQ
     * maxSize -> max size of IPQ (for initializing capacity)
    */
    int maxSize, size;
    /**
     * vals -> values array, where index is the key index
     * pm   -> position map, maps key index to index in heap
     * im   -> inverse map, maps index in heap to key index
    */
    vector<int> vals, pm, im;
};

int main() {
    // solution
    MinIndexedPriorityQueue q(15);
    vector<int> vals = {3, 15, 11, 17, 7, 9, 2, 1, 6, 5, 16, 4, 242, 4, 6666, 743, 3, 32};
    q.poll();

    for(int i = 0; i < 12; ++i) {
        q.insert(i, vals[i]);

        //q.printAll();
    }

    q.printAll();
    LOG(q.top());

    q.poll();
    LOG(q.top());

    q.poll();
    LOG(q.top());

    q.poll();
    LOG(q.top());
    
    q.poll();
    LOG(q.top());
    
    q.poll();
    LOG(q.top());
    
    q.poll();
    LOG(q.top());
    
    q.poll();
    LOG(q.top());
    
    q.poll();
    LOG(q.top());
    
    q.poll();
    LOG(q.top());



    return 0;
}