/* What is a Palindrome?**  
A **Palindrome** is a string that **reads the same forward and backward**.  

✅ **Examples:**  
- **"madam"** → ✅ **Palindrome**  
- **"racecar"** → ✅ **Palindrome**  
- **"hello"** → ❌ **Not a Palindrome**  
*/
  
#include <iostream>  // Include input-output stream library

// Define a class called Solution
class Solution {
public:
    // Function to check if a string is a palindrome
    bool isPalindrome(std::string str) {
        int left = 0, right = str.length() - 1; // Set two pointers: start and end

        while (left < right) { // Loop until the middle of the string
            if (str[left] != str[right]) // If characters don't match, not a palindrome
                return false;
            left++;  // Move left pointer forward
            right--; // Move right pointer backward
        }

        return true; // If loop completes, it's a palindrome
    }
};

int main() {
    Solution sol; // Create an object of the Solution class
    std::string str; // Variable to store user input

    std::cout << "Enter a string: "; // Ask user for input
    std::cin >> str; // Read the input string

    // Check if the string is a palindrome and display the result
    if (sol.isPalindrome(str)) {
        std::cout << str << " is a Palindrome." << std::endl;
    } else {
        std::cout << str << " is NOT a Palindrome." << std::endl;
    }

    return 0; // Exit the program
}
