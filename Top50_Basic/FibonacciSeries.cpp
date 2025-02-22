#include <iostream>  

// Define a class called Solution
class Solution {
public:
    // Function to print Fibonacci series up to 'n' terms
    void fibonacciSeries(int n) {
        int first = 0, second = 1, next; // Initialize first two Fibonacci numbers

        std::cout << "Fibonacci Series: ";

        for (int i = 0; i <= n; i++) { // Loop to generate Fibonacci sequence
            std::cout << first << " "; // Print the current Fibonacci number
            next = first + second; // Compute the next Fibonacci number
            first = second; // Update first to the next value(second)
            second = next; // Update second to the new computed value(next)
        }

        std::cout << std::endl; // Move to the next line after printing series
    }
};

int main() {
    Solution sol; // Create an object of the Solution class
    int n; // Variable to store user input

    std::cout << "Enter the number of terms: "; // Ask user for input
    std::cin >> n; // Read the input value

    sol.fibonacciSeries(n); // Call function to print Fibonacci series

    return 0; // Exit the program
}
/*
Output:
Enter the number of terms: 15
Fibonacci Series: 0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 
*/
