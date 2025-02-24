/* Find numbers that satisfy both conditions.
Problem:
Write a function to find numbers that are either divisible by 9 or contain the digit '9' between 1 and 100.
*/

Edit
#include <iostream>
#include <string>

class Solution {
public:
    bool containsDigit(int num, char digit) {
        std::string strNum = std::to_string(num);  // Convert number to string
        return strNum.find(digit) != std::string::npos;
    }

    void findSpecialNumbers(int start, int end) {
        for (int i = start; i <= end; ++i) {
            if (i % 9 == 0 || containsDigit(i, '9')) {
                std::cout << i << " ";
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    Solution solution;
    std::cout << "Numbers divisible by 9 or containing '9' between 1 and 100: ";
    solution.findSpecialNumbers(1, 100);

    return 0;
}
/*
Output:
Numbers divisible by 9 or containing '9' between 1 and 100: 9 18 27 36 45 54 63 72 81 90 99
*/
