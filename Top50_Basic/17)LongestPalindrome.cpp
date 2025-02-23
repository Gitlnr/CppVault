#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    // Function to check if a string is a palindrome
    bool isPalindrome(const std::string& str) {
        int left = 0, right = str.size() - 1;
        while (left < right) {
            if (str[left] != str[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    // Function to find the longest palindrome in an array
    std::string longestPalindrome(const std::vector<std::string>& arr) {
        std::string longestPal = "";

        // Step 1: Iterate through all possible substrings in the array
        for (const std::string& str : arr) {
            // Step 2: Check if each string is a palindrome
            if (isPalindrome(str) && str.length() > longestPal.length()) {
                longestPal = str;  // Update longest palindrome found
            }
        }

        return longestPal;  // Return the longest palindrome found
    }
};

int main() {
    Solution solution;
    std::vector<std::string> arr = {"hello", "racecar", "madam", "world", "level"};

    std::cout << "Array of strings: ";
    for (const auto& str : arr) std::cout << str << " ";
    std::cout << std::endl;

    // Find the longest palindrome
    std::string result = solution.longestPalindrome(arr);

    std::cout << "Longest palindrome: " << result << std::endl;

    return 0;
}


//for integer
#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    // Function to check if a number is a palindrome
    bool isPalindrome(int num) {
        std::string str = std::to_string(num);  // Convert number to string
        int left = 0, right = str.size() - 1;

        // Compare characters from both ends
        while (left < right) {
            if (str[left] != str[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    // Function to find the longest palindrome in an array of integers
    int longestPalindrome(const std::vector<int>& arr) {
        int longestPal = -1;  // Initialize with a negative value (to handle no palindrome case)

        // Step 1: Iterate through the array of integers
        for (int num : arr) {
            // Step 2: Check if the number is a palindrome
            if (isPalindrome(num) && num > longestPal) {
                longestPal = num;  // Update longest palindrome found
            }
        }

        return longestPal;  // Return the longest palindrome found
    }
};

int main() {
    Solution solution;
    std::vector<int> arr = {1, 121, 55551, 545545, 10111, 90};

    std::cout << "Array of integers: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << std::endl;

    // Find the longest palindrome
    int result = solution.longestPalindrome(arr);

    std::cout << "Longest palindrome: " << result << std::endl;

    return 0;
}
