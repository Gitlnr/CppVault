/*Check if a number contains a specific digit.
Problem:
Write a function to check if a number contains '7'.
*/
#include <iostream>
#include <string>

class Solution {
public:
    bool containsDigit(int num, char digit) {
        std::string strNum = std::to_string(num);  // Convert number to string
        return strNum.find(digit) != std::string::npos;  // Check if 'digit' exists
    }
};

int main() {
    Solution solution;
    int num = 172;

    // Check if number contains '7'
    if (solution.containsDigit(num, '7')) {
        std::cout << num << " contains '7'." << std::endl;
    } else {
        std::cout << num << " does not contain '7'." << std::endl;
    }

    return 0;
}
/*
Output:
172 contains '7'.
*/
