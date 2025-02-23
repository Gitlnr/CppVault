/*🔹 Approach:
Count the frequency of each element in the array.
Filter the elements that appear only once (non-repeating elements).
Return or print the non-repeating elements.*/

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    // Function to find non-repeating elements in an array
    void findNonRepeatingElements(const std::vector<int>& arr) {
        std::unordered_map<int, int> freqMap;

        // Step 1: Count the frequency of each element
        for (int num : arr) {
            freqMap[num]++;
        }

        // Step 2: Print elements that have a frequency of 1
        std::cout << "Non-repeating elements: ";
        for (const auto& entry : freqMap) {
            if (entry.second == 1) {
                std::cout << entry.first << " ";
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    Solution solution;
    std::vector<int> arr = {4, 5, 7, 5, 4, 8, 9};

    std::cout << "Original array: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << std::endl;

    // Find non-repeating elements
    solution.findNonRepeatingElements(arr);

    return 0;
}
