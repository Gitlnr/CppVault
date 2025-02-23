/*
A **non-repeating character** is a character that appears only **once** in the string.  
To find such characters:  
1. **Count the frequency** of each character.  
2. **Check which characters appear only once.**  
*/
#include <iostream>
#include <unordered_map>

class Solution {
public:
    // Function to find and print non-repeating characters
    void findNonRepeatingCharacters(const std::string& str) {
        std::unordered_map<char, int> charCount; // Stores frequency of each character

        // Count occurrences of each character
        for (char ch : str) {
            charCount[ch]++;
        }

        std::cout << "Non-repeating characters: ";
        bool found = false;

        // Print characters that appear only once
        for (char ch : str) {
            if (charCount[ch] == 1) {
                std::cout << ch << " ";
                found = true;
            }
        }

        if (!found) {
            std::cout << "None"; // If no unique characters exist
        }
        
        std::cout << std::endl;
    }
};

int main() {
    Solution solution;
    std::string input;

    // Input string
    std::cout << "Enter a string: ";
    std::cin >> input;

    // Find and print non-repeating characters
    solution.findNonRepeatingCharacters(input);

    return 0;
}
/*
### **Example Outputs**
#### **Input 1:**  
```
Enter a string: swiss
```
#### **Output:**  
```
Non-repeating characters: w 
```

#### **Input 2:**  
```
Enter a string: programming
```
#### **Output:**  
```
Non-repeating characters: p o g r a i n 
```

#### **Input 3:**  
```
Enter a string: aabbcc
```
#### **Output:**  
```
Non-repeating characters: None
*/
