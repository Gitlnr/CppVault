/*n "A type" number** is an integer that satisfies **at least one** of these conditions:  
1️⃣ **It is a multiple of 3.**  
2️⃣ **It contains the digit '3'** in its decimal representation.  

### **Examples:**  
✅ **9** → (Multiple of 3)  
✅ **31** → (Contains '3')  
✅ **42** → (Multiple of 3)  
✅ **135** → (Multiple of 3 & Contains '3')  
❌ **25** → (Neither multiple of 3 nor contains '3')  
*/


#include <iostream>
#include <string>

class Solution {
public:
    // Function to check if a number is "A type"
    bool isAType(int num) {
        // Condition 1: Check if num is a multiple of 3
        if (num % 3 == 0) return true;
        
        // Condition 2: Check if num contains '3'
        std::string strNum = std::to_string(num);
        if (strNum.find('3') != std::string::npos) return true;

        return false; // If neither condition is met
    }
};

int main() {
    Solution solution;
    int num;
    
    // Input number
    std::cout << "Enter a number: ";
    std::cin >> num;
    
    // Check and print the result
    if (solution.isAType(num)) {
        std::cout << num << " is an A type number." << std::endl;
    } else {
        std::cout << num << " is NOT an A type number." << std::endl;
    }
    
    return 0;
}

/*
### **🔹 Example Runs**  
#### **Input:**  
```
Enter a number: 42
```
#### **Output:**  
```
42 is an A type number.
```

#### **Input:**  
```
Enter a number: 25
```
#### **Output:**  
```
25 is NOT an A type number.
*/
