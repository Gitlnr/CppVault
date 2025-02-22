#include <iostream>  // Include input-output stream library

// Define a class called Solution
class Solution {
public:
    // Function to calculate GCD using the Euclidean Algorithm
    int findGCD(int a, int b) {
        while (b != 0) {  // Loop until remainder becomes 0
            int temp = b; // Store the value of b
            b = a % b;    // Update b to the remainder of a divided by b
            a = temp;     // Update a to the previous value of b
        }
        return a; // Return the final GCD value
    }
};

int main() {
    Solution sol; // Create an object of the Solution class
    int num1, num2; // Variables to store user input

    std::cout << "Enter two numbers: "; // Ask user for input
    std::cin >> num1 >> num2; // Read input numbers

    int gcd = sol.findGCD(num1, num2); // Call function to find GCD
    std::cout << "GCD of " << num1 << " and " << num2 << " is: " << gcd << std::endl; // Print result

    return 0; // Exit the program
}



/*
Enter two numbers: 12 18
GCD of 12 and 18 is: 6

###Step-by-Step Calculation:
We repeatedly replace (a, b) → (b, a % b) until b becomes 0.  

1. Initial values: 
   - ( a = 12 ), ( b = 18 )  
   - Compute ( 12 \mod 18 = 12 \) (since 12 < 18, remainder is 12)  
   - New values: ( a = 18 ), ( b = 12 )  

2. **Next iteration:**  
   - Compute \( 18 \mod 12 = 6 \)  
   - **New values:** \( a = 12 \), \( b = 6 \)  

3. **Next iteration:**  
   - Compute \( 12 \mod 6 = 0 \)  
   - **New values:** \( a = 6 \), \( b = 0 \)  

4. **Stop condition:** Since **b = 0**, the GCD is the last non-zero `a` value, which is **6** ✅.  

This is why GCD(12, 18) = 6!



GCD (Greatest Common Divisor)
The GCD of two numbers is the largest number that divides both numbers exactly without leaving a remainder.

Example:
GCD of 12 and 18

Factors of 12: 1, 2, 3, 4, 6, 12
Factors of 18: 1, 2, 3, 6, 9, 18
Common factors: 1, 2, 3, 6
Greatest common factor: 6 
*/
