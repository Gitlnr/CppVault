/*Example:
Input: `"hello"`  
Output:  
h: 1
e: 1
l: 2
o: 1
  */

#include <iostream>  // Include input-output stream library
#include <map>       // Include map library for frequency storage

// Define a class called Solution
class Solution {
public:
    // Function to count and display character frequency in a string
    void charFrequency(std::string str) {
        std::unorderd_map<char, int> freqMap; // Map to store character frequencies

        // Loop through the string and count occurrences
        for (char ch : str) {
            freqMap[ch]++; // Increment the count of the character
        }

        // Display the frequency of each character
        std::cout << "Character Frequencies:\n";
        for (auto pair : freqMap) { // Iterate through the map
            std::cout << pair.first << ": " << pair.second << std::endl;
        }
    }
};

int main() {
    Solution sol; // Create an object of the Solution class
    std::string str; // Variable to store user input

    std::cout << "Enter a string: "; // Ask user for input
    std::cin >> str; // Read input string

    sol.charFrequency(str); // Call function to calculate and display frequencies

    return 0; // Exit the program
}
