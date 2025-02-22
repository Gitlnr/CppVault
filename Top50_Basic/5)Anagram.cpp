/* What is an Anagram?**  
Two strings are **Anagrams** if they contain the **same characters in the same frequency**, but in **any order**.  

✅ **Example:**  
- **"listen"** and **"silent"** → ✅ **Anagram**  
- **"hello"** and **"world"** → ❌ **Not an Anagram**  
*/

#include <iostream>   // Include input-output stream library
#include <algorithm>  // Include algorithm library for sorting

// Define a class called Solution
class Solution {
public:
    // Function to check if two strings are Anagrams
    bool isAnagram(std::string str1, std::string str2) {
        if (str1.length() != str2.length()) // If lengths are different, not an anagram
            return false;

        // Sort both strings
        std::sort(str1.begin(), str1.end());
        std::sort(str2.begin(), str2.end());

        return str1 == str2; // If sorted strings are equal, they are anagrams
    }
};

int main() {
    Solution sol; // Create an object of the Solution class
    std::string str1, str2; // Variables to store user input

    std::cout << "Enter first string: "; // Ask user for first string
    std::cin >> str1; // Read first string
    std::cout << "Enter second string: "; // Ask user for second string
    std::cin >> str2; // Read second string

    // Check if the strings are anagrams and display the result
    if (sol.isAnagram(str1, str2)) {
        std::cout << "The strings are Anagrams." << std::endl;
    } else {
        std::cout << "The strings are NOT Anagrams." << std::endl;
    }

    return 0; // Exit the program
}

/* 
Enter first string: listen  
Enter second string: silent  

✅ **Output:**
The strings are Anagrams.
*/
