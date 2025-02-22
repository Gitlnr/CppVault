/*
Match happens when:

* can match a sequence of characters (including empty).
? matches exactly one character.
All non-wildcard characters are matched exactly in both string and pattern.
Doesn't match when:

? cannot match exactly one character.
* cannot handle the sequence (either doesn't match enough or too many characters).
The lengths or structure of the string and pattern do not align properly.

*/

#include <iostream>  // Include input-output stream library
#include <vector>    // Include vector for dynamic programming

// Define a class called Solution
class Solution {
public:
    // Function to check if two strings match with wildcard support
    bool isMatch(std::string str, std::string pattern) {
        int m = str.length(), n = pattern.length();
        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));
/*m + 1 rows are used because we need an extra row to handle the case when the string is empty (i.e., matching an empty string with the pattern).
The first row represents the case where the string is empty, so it helps us manage patterns like * and ? properly.
n + 1 columns are used to handle the case where the pattern is empty (i.e., matching the string with an empty pattern).*/

        // Base case: empty pattern matches empty string
        dp[0][0] = true;

        // Handle patterns starting with '*' (can match empty string)
        for (int j = 1; j <= n; j++) {
            if (pattern[j - 1] == '*')
                dp[0][j] = dp[0][j - 1]; // '*' matches empty sequence
        }

        // Fill the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (pattern[j - 1] == str[i - 1] || pattern[j - 1] == '?') {
                    // Exact match or '?' matches any single character
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (pattern[j - 1] == '*') {
                    // '*' can match empty (dp[i][j-1]) or match one/more characters (dp[i-1][j])
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
            }
        }

        return dp[m][n]; // Return final result
    }
};

int main() {
    Solution sol; // Create an object of the Solution class
    std::string str, pattern; // Variables to store user input

    std::cout << "Enter the string: "; // Ask user for string input
    std::cin >> str; // Read string
    std::cout << "Enter the pattern (with wildcards * and ?): "; // Ask for pattern input
    std::cin >> pattern; // Read pattern

    // Check if the string matches the pattern and display the result
    if (sol.isMatch(str, pattern)) {
        std::cout << "The string matches the pattern." << std::endl;
    } else {
        std::cout << "The string does NOT match the pattern." << std::endl;
    }

    return 0; // Exit the program
}
/*
Example Code Walkthrough:
Let’s consider this example again:

String: "hello"
Pattern: "h*llo"
The DP table will be built like this:

h	*	l	l	o
0	1	2	3	4
---	-----	-----	-----	-----	-----
h	T	T	F	F	F
e	F	T	F	F	F
l	F	T	T	T	F
l	F	T	T	T	T
o	F	T	T	T	T
At the end, dp[m][n] will tell us whether the string matches the pattern.
*/
