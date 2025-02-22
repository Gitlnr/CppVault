#include <iostream>  

// Define a class called Solution
class Solution {
public:
    // Function to reverse a given number
    int reverseNumber(int num) {
        int reversed = 0; // Variable to store the reversed number

        while (num != 0) { // Loop until num becomes 0
            reversed = reversed * 10 + num % 10; // Extract last digit and append to reversed
            num /= 10; // Remove the last digit from num
        }

        return reversed; // Return the reversed number
    }
};


int main() {
    Solution sol; // Create an object of the Solution class
    int num; // Variable to store user input

    std::cout << "Enter a number: "; // Ask user for input
    std::cin >> num; // Read input number

    int reversedNum = sol.reverseNumber(num); // Call the function to reverse the number
    std::cout << "Reversed Number: " << reversedNum << std::endl; // Print the reversed number

    return 0; // Exit the program
}
/*
Output:
Enter a number: 567
Reversed Number: 765
*/
