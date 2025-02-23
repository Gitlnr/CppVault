/*🔹 Approach:
Circular rotation means that elements of the array are moved to the right (or left) by K positions, and the elements that go past the end of the array come back to the beginning.
Right rotation: Elements at the end of the array move to the beginning.//used in below code
Left rotation: Elements at the beginning of the array move to the end.
*/

#include <iostream>
#include <vector>

class Solution {
public:
    // Function to perform right circular rotation by K positions
    void rightRotate(std::vector<int>& arr, int K) {
        int n = arr.size();
        K = K % n;  // To handle cases where K > n

        // Step 1: Reverse the entire array
        reverse(arr, 0, n - 1);

        // Step 2: Reverse the first K elements
        reverse(arr, 0, K - 1);

        // Step 3: Reverse the remaining elements
        reverse(arr, K, n - 1);
    }

    // Function to reverse a part of the array from index 'start' to 'end'
    void reverse(std::vector<int>& arr, int start, int end) {
        while (start < end) {
            std::swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }

    // Function to print the array
    void printArray(const std::vector<int>& arr) {
        for (int num : arr) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Solution solution;
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

    std::cout << "Original array: ";
    solution.printArray(arr);

    int K = 3; // Number of positions to rotate

    // Perform right circular rotation by K positions
    solution.rightRotate(arr, K);

    std::cout << "Array after right rotation by " << K << " positions: ";
    solution.printArray(arr);

    return 0;
}

/*Array after right rotation by 3 positions: 5 6 7 1 2 3 4
*/
