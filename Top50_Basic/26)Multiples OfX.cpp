/* Find all numbers in a given range that are multiples of X.
Problem:
Write a function that finds all numbers divisible by 5 in the range [1, 50].
*/
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> findMultiples(int start, int end, int x) {
        std::vector<int> result;
        for (int i = start; i <= end; ++i) {
            if (i % x == 0) {  // Check if divisible by x
                result.push_back(i);
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    std::vector<int> multiples = solution.findMultiples(1, 50, 5);

    // Print the result
    std::cout << "Multiples of 5 between 1 and 50: ";
    for (int num : multiples) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
/*
Output:
Multiples of 5 between 1 and 50: 5 10 15 20 25 30 35 40 45 50
*/
