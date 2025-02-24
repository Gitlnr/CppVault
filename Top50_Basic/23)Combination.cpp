#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Solution {
    private:
    void helperFunction(vector<int>&nums, vector<int>&subset,int index){

        cout<<"[";
        for(int i=0;i<subset.size();i++){
            cout<<subset[i];
            if(i<subset.size()-1){
                cout<<",";
            }
        }
        cout<<"]";

        for(int i=index;i<nums.size();i++){
            subset.push_back(nums[i]);
            helperFunction(nums,subset,i+1);
            subset.pop_back();
        }
    }
    public:
    void combination(vector<int>nums){
        int index =0;
        vector<int>subset;
        helperFunction(nums,subset,0);
        return ;
    }
};
int main() {
    Solution sol;
    vector<int>nums={1,2,3};
    sol.combination(nums);
    return 0;
}
