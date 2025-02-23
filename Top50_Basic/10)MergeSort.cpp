/*What is Merge Sort? (Simple Terms)
Merge Sort is a divide and conquer sorting algorithm that:

Divides the array into two halves.
Sorts each half separately.
Merges the sorted halves back together in the correct order.
✅ Why is Merge Sort good?

It has a time complexity of 
𝑂(𝑛log𝑛), which is faster than Bubble Sort for large datasets.
It is stable (preserves the order of equal elements).
Works well for large datasets and linked lists.*/

#include <iostream>
#include <vector>

class Solution {
public:
    // Function to merge two sorted halves of the array
    void merge(std::vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1; // Size of left sub-array
        int n2 = right - mid;     // Size of right sub-array

        // Create temporary arrays
        std::vector<int> leftArr(n1);
        std::vector<int> rightArr(n2);

        // Copy data to temporary arrays
        for (int i = 0; i < n1; i++)
            leftArr[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            rightArr[j] = arr[mid + 1 + j];

        // Merge the two sorted arrays
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k] = leftArr[i];
                i++;
            } else {
                arr[k] = rightArr[j];
                j++;
            }
            k++;
        }

        // Copy any remaining elements of leftArr
        while (i < n1) {
            arr[k] = leftArr[i];
            i++;
            k++;
        }

        // Copy any remaining elements of rightArr
        while (j < n2) {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
    }

    // Function to perform Merge Sort
    void mergeSort(std::vector<int>& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2; // Find the middle index

            // Recursively sort first and second halves
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);

            // Merge the sorted halves
            merge(arr, left, mid, right);
        }
    }

    // Function to print the array
    void printArray(const std::vector<int>& arr) {
        for (int num : arr)
            std::cout << num << " ";
        std::cout << std::endl;
    }
};

int main() {
    Solution solution; // Create an instance of Solution
    std::vector<int> arr = {38, 27, 43, 3, 9, 82, 10}; // Sample array

    std::cout << "Original array: ";
    solution.printArray(arr);

    solution.mergeSort(arr, 0, arr.size() - 1); // Call Merge Sort function

    std::cout << "Sorted array: ";
    solution.printArray(arr);

    return 0;
}
/*Yes, exactly! The **execution order** of the recursive calls follows a **depth-first approach**, meaning:  

1. **First**, `mergeSort(arr, left, mid);` keeps executing **until** it reaches the base case (`left == right`).  
2. **Then**, `mergeSort(arr, mid + 1, right);` starts executing **after the left half is fully processed**.  
3. **Finally**, `merge(arr, left, mid, right);` executes **only after both left and right halves are sorted**.  

---

### **Execution Order Breakdown**
For an array `[38, 27, 43, 3, 9]`:

#### **First Call:** `mergeSort(arr, 0, 4)`
- `mid = 2`, so we split into `[38, 27, 43]` and `[3, 9]`.

#### **Step 1: Process Left Half `[38, 27, 43]` (Recursive Call)**
- Calls `mergeSort(arr, 0, 2)`.
- `mid = 1`, so we split into `[38, 27]` and `[43]`.

#### **Step 2: Process `[38, 27]`**
- Calls `mergeSort(arr, 0, 1)`.
- `mid = 0`, so we split into `[38]` and `[27]`.

#### **Step 3: Base Case Reached (`left == right`)**
- `mergeSort(arr, 0, 0)` → Stops (single element `[38]`).
- `mergeSort(arr, 1, 1)` → Stops (single element `[27]`).

#### **Step 4: Merge `[38]` and `[27]`**
- Now `merge(arr, 0, 0, 1)` executes to merge `[38]` and `[27]` → `[27, 38]`.

#### **Step 5: Process `[43]`**
- `mergeSort(arr, 2, 2)` → Stops (single element `[43]`).

#### **Step 6: Merge `[27, 38]` and `[43]`**
- Now `merge(arr, 0, 1, 2)` executes to merge `[27, 38]` and `[43]` → `[27, 38, 43]`.

#### **Step 7: Process Right Half `[3, 9]`**
- Calls `mergeSort(arr, 3, 4)`.
- `mid = 3`, so we split into `[3]` and `[9]`.

#### **Step 8: Base Case Reached (`left == right`)**
- `mergeSort(arr, 3, 3)` → Stops (single element `[3]`).
- `mergeSort(arr, 4, 4)` → Stops (single element `[9]`).

#### **Step 9: Merge `[3]` and `[9]`**
- Now `merge(arr, 3, 3, 4)` executes to merge `[3]` and `[9]` → `[3, 9]`.

#### **Step 10: Merge `[27, 38, 43]` and `[3, 9]`**
- Now `merge(arr, 0, 2, 4)` executes to merge `[27, 38, 43]` and `[3, 9]` → `[3, 9, 27, 38, 43]` (Final Sorted Array 🎉).

---

### **Conclusion: Execution Flow**
1. **Left side sorts first (deepest recursive call).**  
2. **Then, the right side sorts.**  
3. **Finally, the merge happens bottom-up.**  

🚀 **Recursion first "splits" until it reaches the base case, then it "merges" back up.***/
