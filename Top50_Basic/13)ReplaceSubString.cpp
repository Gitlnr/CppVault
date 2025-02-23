
#include <iostream>
#include <string>

class Solution {
public:
    // Function to replace all occurrences of oldSub with newSub in str
    std::string replaceSubstring(std::string str, const std::string& oldSub, const std::string& newSub) {
        size_t pos = 0; // Start from the beginning of the string
      
      /*size_t is an unsigned integer type specifically designed for sizes and indices.
        It is used for things like array indices, string lengths, and memory sizes.
        std::string::find() returns size_t because an index should never be negative.
     */

        // Loop through the string to find and replace all occurrences of oldSub
        while ((pos = str.find(oldSub, pos)) != std::string::npos) {
            // Replace oldSub with newSub at the found position
            str.replace(pos, oldSub.length(), newSub);

            // Move 'pos' forward to avoid infinite loop
            pos += newSub.length();
        }
        return str;
    }
};

int main() {
    Solution solution;
    std::string str = "I love cats. Cats are cute.";
    std::string oldSub = "Cats";
    std::string newSub = "Dogs";

    std::string result = solution.replaceSubstring(str, oldSub, newSub);
    std::cout << "Updated string: " << result << std::endl;

    return 0;
}
/*
### **🔹 Key Takeaways**
1. **`str.find(oldSub, pos)`** → Finds the first occurrence of `oldSub` starting from `pos`.
2. **`str.replace(pos, oldSub.length(), newSub)`** → Replaces `oldSub` with `newSub`.
3. **`pos += newSub.length();`** → Moves `pos` forward to avoid replacing the same substring repeatedly.

💡 **This ensures that ALL occurrences of `oldSub` are replaced!** 🚀
*/
