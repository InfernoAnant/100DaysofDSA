/*You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int lp = 0, rp = height.size() - 1;
        int maxwater = 0;
        while(lp < rp){
            int w = rp - lp;
            int ht = min(height[lp], height[rp]);
            int currwater = w * ht;
            maxwater = max(maxwater, currwater);

            height[lp] < height[rp] ? lp++ : rp--;
        }
        return maxwater;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> height = {1,8,6,2,5,4,8,3,7};

    int result = sol.maxArea(height);
    cout << "Maximum area of water: " << result << endl;

    return 0;
}
