//Method 1: Using Bitwise AND (n & (n - 1)) - Efficient
cpp
Copy
Edit
#include <iostream>
using namespace std;

int countSetBits(int n) {
    int count = 0;
    while (n) {
        n = n & (n - 1);  // Removes the rightmost set bit
        count++;
    }
    return count;
}
int main() {
    Solution sol;
    int count =sol. numOfOnes(5);
    cout<<count<<endl;
    return 0;
}
/*Explanation (Optimized Method)
n & (n - 1) removes the rightmost set bit in each iteration.
Example for n = 5 (101₂):
101 & 100 → 100 (1 bit removed)
100 & 011 → 000 (1 bit removed)
Time Complexity: O(k) (where k = number of 1s)*/

/*
Alternative Method: Using Bit Shifting (n >> i)
int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += (n & 1);  // Check last bit
        n >>= 1;           // Shift right
    }
    return count;
}
Slower than the optimized method, but still works.
Complexity: O(log n) (depends on the number of bits).*/
