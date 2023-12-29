# Assignment 1 – Data Classification and Search

**Team:** Rhuan Lucas Barbosa Fernandes and Davi Santos Ferrarez

**GitHub Link:** [Repository](https://github.com/RhuanLucass/cpd-trabalho01)

## 1. Introduction

### Bubble sort
Bubble sort has a complexity of O(n²) and isn't recommended for large datasets. This algorithm compares each element with the next one and swaps them if they are out of order. The loop continues until all elements are sorted.

### Selection sort
Not a stable algorithm and has a complexity of O(n²) in both best and worst cases. It involves finding the smallest element and placing it at the beginning, repeating this routine for the rest of the array.

### Insertion sort
Insertion sort has a complexity of O(n²) and is efficient for small datasets. It compares the current element with its predecessors and places it in the correct position.

### Quicksort
Efficient and based on divide-and-conquer but not stable. It has a complexity of O(n log n) in the best and average cases, O(n²) in the worst case. It uses a pivot to partition the array.

### Merge sort
Complexity O(n log n), efficient for large inputs. It divides the array in half recursively and merges the sorted subarrays.

### Heapsort
Unstable but always O(n log n). It uses a binary heap to sort elements, maintained within the array itself.

## 2. Table

Four arrays of 25,000 elements were used due to computational limitations, totaling the suggested input of 100,000.

| Arrays (Size = 100000) | Bubble sort | Selection sort | Insertion sort | Quick sort | Merge sort | Heap sort |
| ----------------------- | ----------- | -------------- | -------------- | ---------- | ---------- | --------- |
| Random                  | 7.328 s     | 2.930 s        | 1.668 s        | 0.023 s    | 0.035 s    | 0.021 s   |
| Ascending               | 3.150 s     | 2.928 s        | 0.001 s        | 3.166 s    | 0.023 s    | 0.014 s   |
| Descending              | 6.043 s     | 2.972 s        | 3.292 s        | 3.157 s    | 0.016 s    | 0.014 s   |

## 3. Conclusion

Bubble sort performed the worst on random arrays due to a high number of comparisons. Conversely, Heapsort was the most efficient due to its binary tree structure.

In ascending arrays, Insertion sort showed the best performance as the elements were already sorted. Conversely, Quicksort performed the worst due to its partitioning routine.

In descending arrays, Bubble sort again showed the worst performance, while Heapsort displayed the best due to its binary tree structure.
