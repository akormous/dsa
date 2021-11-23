## Sorting Algorithms

<details>
    <summary>Bubble Sort</summary>

- TIME COMPLEXITY - `O(n^2)`
- SPACE COMPLEXITY - `O(1)`
- Start from the beginning of the array and swap the first two elements if the first is greater than the second.
- Then, go to the next pair, and so on.
- The bigger item slowly "bubble" up to the end of the list

</details>

<details>
    <summary>Selection Sort</summary>

- TIME COMPLEXITY - `O(n^2)`
- SPACE COMPLEXITY - `O(1)`
- Find the smallest element using a linear scan and move it to the front (swapping it with the front element)
</details>

<details>
    <summary>Merge Sort</summary>

- TIME COMPLEXITY - `O(n log(n))`
- SPACE COMPLEXITY - `O(n)`
- It divides the array in half, sorts each of those halves, and then merges them back together.
- Recursively call for the left part and right part
</details>

<details>
    <summary>Quick Sort</summary>

- TIME COMPLEXITY
    - `O(n log(n))` (Average)
    - `O(n^2)`      (Worst Case)
- SPACE COMPLEXITY - `O(log (n))`
- Pick a random element aka pivot and partition the array, such that all numbers that are less than the pivot come before all the elements that are greater than it.
- The partitioning can be performed efficiently through a series of swaps
</details>

<details>
    <summary>Counting Sort</summary>

- TIME COMPLEXITY - `O(n + k)` 
- SPACE COMPLEXITY - `O(n + k)`
- where `k` is the range of the input 
- It is based on keys between a specific range.
- It works by counting the number of objects having distinct key values ( `freq[]` )
</details>

<details>
    <summary>Radix Sort</summary>

- TIME COMPLEXITY - `O((n + b) * logb(k))`
- SPACE COMPLEXITY - `O(n + 2^d)`
- b = the base (for decimal b = 10)
- n = number of elements in the array
- k = maximum value in the array
- The idea of Radix Sort is to do digit by digit sort starting from the least significant digit to the most significant digit
- It uses counting sort subroutine to sort


</details>