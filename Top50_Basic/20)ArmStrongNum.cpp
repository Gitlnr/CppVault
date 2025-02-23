/*An Armstrong number (also known as a Narcissistic number) for a given number of n is a number that is equal to the sum of its own digits each raised to the power of the number of digits.
🔹 Steps to Check for Armstrong Number:
Calculate the number of digits in the number n.
For each digit, raise it to the power of the number of digits.
Sum all these powered digits.
If the sum equals the original number, then it's an Armstrong number.

For exmaple :153 
1^3+5^3+3^3 =153 is a armstrong number
*/

#include <iostream>
#include <cmath>

class Solution {
public:
    // Function to check if a number is Armstrong
    bool isArmstrong(int n) {
        int originalNumber = n;  // Store the original number
        int numDigits = 0;
        int sum = 0;

        // Step 1: Find the number of digits
        while (n != 0) {
            n /= 10;  // Remove the last digit
            numDigits++;
        }

        n = originalNumber;  // Reset n to the original number

        // Step 2: Calculate the sum of digits raised to the power of numDigits
        while (n != 0) {
            int digit = n % 10;  // Get the last digit
            sum += std::pow(digit, numDigits);  // Add the digit raised to the power
            n /= 10;  // Remove the last digit
        }

        // Step 3: Check if the sum equals the original number
        return sum == originalNumber;
    }
};

int main() {
    Solution solution;
    int num;

    // Input number
    std::cout << "Enter a number: ";
    std::cin >> num;

    // Check and print if the number is Armstrong
    if (solution.isArmstrong(num)) {
        std::cout << num << " is an Armstrong number." << std::endl;
    } else {
        std::cout << num << " is not an Armstrong number." << std::endl;
    }

    return 0;
}
