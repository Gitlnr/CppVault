#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Solution {
    public:
        bool prime(int n) {
            if(n<2){
                return false;
            }

            for(int i =2;i*i<=n;i++){
                if(n%i==0){
                    return false;
                }
            }

            return true;

        }
    };

int main() {
    Solution sol;
    int result = sol.prime(8);
    cout<<result;


    return 0;
}
