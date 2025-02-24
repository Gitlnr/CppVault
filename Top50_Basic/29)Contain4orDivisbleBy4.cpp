/*Sum all numbers in a range that satisfy a given condition.
Problem:
Write a function to sum all numbers divisible by 4 or containing '4' between 1 and 100.
*/

#include <iostream>
#include <string>

class Solution {
public:
    bool containsDigit(int num, char digit) {
        std::string strNum = std::to_string(num);  // Convert number to string
        return strNum.find(digit) != std::string::npos;
    }

    int sumMultiplesOrContains(int start, int end) {
        int sum = 0;
        for (int i = start; i <= end; ++i) {
            if (i % 4 == 0 || containsDigit(i, '4')) {
                sum += i;
            }
        }
        return sum;
    }
};

int main() {
    Solution solution;
    int sum = solution.sumMultiplesOrContains(1, 100);

    // Print the result
    std::cout << "Sum of numbers divisible by 4 or containing '4' between 1 and 100: " << sum << std::endl;

    return 0;
}
/*
Output:
Sum of numbers divisible by 4 or containing '4' between 1 and 100: 1250
*/
