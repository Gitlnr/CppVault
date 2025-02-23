/*🔹 Steps to Approach:
Sort the array to get the relative ranking of each element.
Map each element to its rank (position in the sorted array).
Replace the original elements in the array by their respective ranks.
🔹 Algorithm:
Create a copy of the array to sort the elements.
Create a mapping of elements to ranks using the sorted array.
For each element in the original array, replace it with its rank based on the mapping.*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    // Function to replace elements by their rank in the array
    void replaceWithRank(std::vector<int>& arr) {
        // Step 1: Copy the array and sort it to get the ranking order
        std::vector<int> sortedArr = arr;
        std::sort(sortedArr.begin(), sortedArr.end());

        // Step 2: Create a mapping from element to its rank
        std::unordered_map<int, int> rankMap;
        int rank = 1;

        for (int i = 0; i < sortedArr.size(); ++i) {
            // If the element is not already in the map, assign it a rank
            if (rankMap.find(sortedArr[i]) == rankMap.end()) {
                rankMap[sortedArr[i]] = rank;
                rank++;
            }
        }

        // Step 3: Replace each element in the original array by its rank
        for (int i = 0; i < arr.size(); ++i) {
            arr[i] = rankMap[arr[i]];
        }
    }
};

int main() {
    Solution solution;
    std::vector<int> arr = {40, 10, 20, 30, 10, 40};

    std::cout << "Original array: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << std::endl;

    // Replace each element by its rank
    solution.replaceWithRank(arr);

    std::cout << "Array with ranks: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}
/*Original array: 40 10 20 30 10 40
Array with ranks: 4 1 2 3 1 4
*/
