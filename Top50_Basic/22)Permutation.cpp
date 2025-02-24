#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Solution {
    private:
    void helperFunction(string& str, int l,int r){
        if(l==r){
            cout<<str<<endl;
            return;
        }

        for(int i =l;i<=r;i++){
            swap(str[l],str[i]);
            helperFunction(str, l+1,r);
            swap(str[l],str[i]);
        }

    }
    public:
    void permutate(string str){
        helperFunction(str,0,str.size()-1);
        return ;
    }
};
int main() {
    Solution sol;
    string str ="ABC";
    sol.permutate(str);
    return 0;
}
