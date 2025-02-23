/*
Leap Year Check**  
A year is a **leap year** if:  
- It is **divisible by 4**, **but not divisible by 100** OR  
- It is **divisible by 400**  
*/

#include <iostream>

class Solution {
public:
    // Function to check if a year is a leap year
    bool isLeapYear(int year) {
        // Leap year conditions
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            return true;  // Leap year
        }
        return false;  // Not a leap year
    }
};

int main() {
    Solution solution;
    int year;

    // Input year
    std::cout << "Enter a year: ";
    std::cin >> year;

    // Check and print result
    if (solution.isLeapYear(year)) {
        std::cout << year << " is a Leap Year.\n";
    } else {
        std::cout << year << " is NOT a Leap Year.\n";
    }

    return 0;
}


/*
### **Example Outputs**
#### **Input:**  
```
Enter a year: 2024
```
#### **Output:**  
```
2024 is a Leap Year.
```

#### **Input:**  
```
Enter a year: 1900
```
#### **Output:**  
```
1900 is NOT a Leap Year.
```

#### **Input:**  
```
Enter a year: 2000
```
#### **Output:**  
```
2000 is a Leap Year.
*/
