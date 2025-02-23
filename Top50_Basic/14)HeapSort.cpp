/*What is Heap Sort?
Heap Sort is a comparison-based sorting algorithm that uses a binary heap data structure.
It follows these two main steps:
Build a Max Heap: Convert the array into a max heap (largest element at the root).
Extract Elements One by One: Swap the root (largest element) with the last element and rebuild the heap.

🔹 Why Use Heap Sort?
✅ Efficient: O(n log n) time complexity (better than Bubble/Selection Sort).
✅ No Extra Space: Sorts in-place with O(1) space.
✅ Works Well for Large Datasets: Used in priority queues and scheduling problems.
*/

#include <iostream>
#include <vector>

class Solution {
public:
    // Function to heapify a subtree rooted at 'i'
    void heapify(std::vector<int>& arr, int n, int i) {
        int largest = i; // Initialize largest as root
        int left = 2 * i + 1; // Left child index
        int right = 2 * i + 2; // Right child index

        // If left child is larger than root
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        // If right child is larger than largest so far
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        // If largest is not root, swap and continue heapifying
        if (largest != i) {
            std::swap(arr[i], arr[largest]); 
            heapify(arr, n, largest); // Recursively heapify the affected subtree
        }
    }

    // Function to perform Heap Sort
    void heapSort(std::vector<int>& arr) {
        int n = arr.size();

        // Step 1: Build Max Heap (rearrange array)
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        // Step 2: Extract elements from heap one by one
        for (int i = n - 1; i > 0; i--) {
            std::swap(arr[0], arr[i]); // Move current root to end
            heapify(arr, i, 0); // Call heapify on reduced heap
        }
    }
};

int main() {
    Solution solution;
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};

    std::cout << "Original array: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << std::endl;

    // Perform Heap Sort
    solution.heapSort(arr);

    std::cout << "Sorted array: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}


/*
### **🔹 Output for the Correct Heap Sort:**

#### **Input Array:**
```
12 11 13 5 6 7
```

#### **Max Heap Construction:**
```
         13
        /  \
      11    12
     /  \   /
    5    6 7
```

#### **Sorted Array after Heap Sort:**
```
5 6 7 11 12 13
*/
