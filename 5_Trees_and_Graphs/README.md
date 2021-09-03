# Trees and Graphs

---

DISCLAIMER: If you don't know what a tree is, don't read the rest of this page.

---

*A Binary Tree is a Tree, but a Tree is not a Binary Tree* - **Barack Obama**

---

<details>
    <summary>Binary Tree</summary>

* Each node has at most 2 children
</details>


<details>
    <summary>Binary Search Tree</summary>

* It is a binary tree but follows a simple rule
* :large_blue_diamond: all left descendants <= the node <  all right descendants :large_orange_diamond: 
* The equality can appear on the left or right side, depends on the situation
</details>


<details>
    <summary>Complete Binary Tree</summary>

* A Binary Tree in which every level is fully filled, except for the last level
* The last level is filled from left to right
</details>


<details>
    <summary>Full Binary Tree</summary>

* A Binary Tree in which every node has either 0 or 2 child nodes
* :exclamation: None of the node has 1 child
</details>


<details>
    <summary>Perfect Binary Tree</summary>

* A Binary Tree
* which is Complete and Full

:star: It has 2<sup>k</sup> - 1 nodes, where k = number of levels in the tree
</details>


## Binary Heaps

<details>
    <summary>Advantages of Heap over Array</summary>

* O(logn) to insert in heap, but O(n) to insert in sorted array
* O(logn) to extract min / max from heap, but O(n) in array
* O(1) to find min / max from heap, but O(n) in array
</details>

<details>
    <summary>Min-heap</summary>

* A min-heap is a *complete* binary tree, where each node is smaller than its children
* The root is the minimum element in the tree
* There are 2 key operations on min-heap `insert` and `extract_min`

`insert`
- Insert the new element at the bottomost rightmost spot (as to maintain the complete binary tree property)
- Fix the tree by swapping the new value with its parent till an appropriate spot is found
- Time Complexity - O(logn)

`extract_min`
- Replace the minimum element at the top with the bottommost rightmost element
- Fix the tree by swapping this value with one of the children till the min-heap property is restored
- Time Complexity - O(logn)

</details>


<details>
    <summary>Max-heap</summary>

* A max-heap is a *complete* binary tree, where each node is larger than its children
* The root is the maximum element in the tree
* There are 2 key operations on max-heap `insert` and `extract_max`

`insert`
- Insert the new element at the bottomost rightmost spot (as to maintain the complete binary tree property)
- Fix the tree by swapping the new value with its parent till an appropriate spot is found
- Time Complexity - O(logn)

`extract_min`
- Replace the maximum element at the top with the bottommost rightmost element
- Fix the tree by swapping this value with one of the children till the max-heap property is restored
- Time Complexity - O(logn)

</details>


