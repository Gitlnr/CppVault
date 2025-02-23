/*What is Bubble Sort? (Concise Explanation for YouTube)
Bubble Sort is a simple sorting algorithm that repeatedly compares and swaps adjacent elements if they are in the wrong order. This process continues until the entire list is sorted.
In simple Bubble Sort sorts the elements in increasing order (smallest to largest) by repeatedly swapping adjacent elements if they are in the wrong order.
✅ Key Idea: Large values "bubble up" to their correct position, like bubbles rising in water.
Time Complexity
Worst/Average Case: 
𝑂(𝑛2) (when the list is reversed)
Best Case: 
𝑂(𝑛)(if the list is already sorted, using an optimized version)
Bubble Sort is simple but inefficient for large lists.*/

#include <iostream>
#include <vector>

class Solution {
public:
    // Function to perform Bubble Sort
    void bubbleSort(std::vector<int>& arr) {
        int n = arr.size(); // Get the size of the array
        bool swapped; // Flag to check if swapping occurred

        // Outer loop for passes
        for (int i = 0; i < n - 1; i++) {
            swapped = false; // Reset swapped flag for each pass

            // Inner loop for comparisons
            for (int j = 0; j < n - i - 1; j++) {
                // Swap if the current element is greater than the next element
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]); // Swap using built-in function
                    swapped = true; // Set flag to true, indicating a swap occurred
                }
            }

            // If no swaps occurred in this pass, the array is already sorted
            if (!swapped)
                break;
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
    Solution solution; // Create an instance of the Solution class
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90}; // Sample array

    std::cout << "Original array: ";
    solution.printArray(arr);

    solution.bubbleSort(arr); // Call Bubble Sort function

    std::cout << "Sorted array: ";
    solution.printArray(arr);

    return 0;
}
/*Example (Step-by-Step for [4, 2, 7, 1])
Initial Array: [4, 2, 7, 1]

1️⃣ Pass 1: Compare & Swap adjacent elements

(4,2) → Swap → [2, 4, 7, 1]
(4,7) → No Swap → [2, 4, 7, 1]
(7,1) → Swap → [2, 4, 1, 7]
2️⃣ Pass 2: Bubble the second-largest element

(2,4) → No Swap → [2, 4, 1, 7]
(4,1) → Swap → [2, 1, 4, 7]
3️⃣ Pass 3: Bubble the smallest unsorted element

(2,1) → Swap → [1, 2, 4, 7]
✅ Sorted Array: [1, 2, 4, 7]

*/
