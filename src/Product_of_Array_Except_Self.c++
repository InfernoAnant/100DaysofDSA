/*Given an integer array nums, return an array answer such that answer[i] 
is equal to the product of all the elements of nums except nums[i].*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        // prefix product
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        // suffix product
        int suffix = 1;
        for (int i = n - 2; i >= 0; i--) {
            suffix = suffix * nums[i + 1];
            ans[i] *= suffix;
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4}; // you can change the input here

    vector<int> result = sol.productExceptSelf(nums);

    cout << "Product of array except self: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
