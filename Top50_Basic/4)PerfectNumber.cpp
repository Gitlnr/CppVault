#include <iostream>  // Include input-output stream library

// Define a class called Solution
class Solution {
public:
    // Function to check if a number is a Perfect Number
    bool isPerfectNumber(int num) {
        int sum = 0; // Variable to store the sum of divisors

        // Loop to find all divisors except the number itself
        for (int i = 1; i <= num / 2; i++) { // Only iterate up to num/2 for efficiency or i<=num
            if (num % i == 0) { // Check if 'i' is a divisor
                sum += i; // Add divisor to sum
            }
        }

        return sum == num; // If sum of divisors equals the number, it's perfect
    }
};

int main() {
    Solution sol; // Create an object of the Solution class
    int num; // Variable to store user input

    std::cout << "Enter a number: "; // Ask user for input
    std::cin >> num; // Read input number

    // Check if the number is perfect and display the result
    if (sol.isPerfectNumber(num)) {
        std::cout << num << " is a Perfect Number." << std::endl;
    } else {
        std::cout << num << " is NOT a Perfect Number." << std::endl;
    }

    return 0; // Exit the program
}



/*###Perfect Number  
A perfect number is a **positive integer** that is **equal to the sum of its proper divisors** (excluding itself).  

### Example: 
✅ 6 is a perfect number**  
- Divisors of 6**: **1, 2, 3**  
- **Sum**: **1 + 2 + 3 = 6** ✅  

✅ **28 is a perfect number**  
- **Divisors of 28**: **1, 2, 4, 7, 14**  
- **Sum**: **1 + 2 + 4 + 7 + 14 = 28** ✅  
*/
