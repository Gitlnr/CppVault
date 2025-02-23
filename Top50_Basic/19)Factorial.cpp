/*To find the **factorial** of a number, we multiply all integers from `1` to `n`, where `n` is the number for which we want to find the factorial.

### **🔹 Factorial Definition**:
- The factorial of a non-negative integer `n` is denoted as `n!`.
- **Formula**:  
  - `n! = n * (n - 1) * (n - 2) * ... * 1`
  - Special case: `0! = 1` (by definition).
*/

#include <iostream>
class Solution {
public:
    // Function to calculate the factorial of a number
    long long factorial(int n) {
        long long result = 1;  // Initialize result to 1

        // Loop to multiply all integers from 1 to n
        for (int i = 1; i <= n; i++) {
            result *= i;  // Multiply the result by current number i
        }

        return result;  // Return the calculated factorial
    }
};

int main() {
    Solution solution;
    int num;

    // Input number
    std::cout << "Enter a number: ";
    std::cin >> num;

    // Check for negative input, factorial is undefined for negative numbers
    if (num < 0) {
        std::cout << "Factorial is undefined for negative numbers!" << std::endl;
    } else {
        // Find and print the factorial
        long long result = solution.factorial(num);
        std::cout << "Factorial of " << num << " is: " << result << std::endl;
    }

    return 0;
}
/*

### **🔹 Example Walkthrough**:

  `5! = 5 * 4 * 3 * 2 * 1 = 120`

#### **Output**:
```
Factorial of 5 is: 120
*/
