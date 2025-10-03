/*You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.
Return the index of the peak element.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st = 1, end = arr.size() - 2;

        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
                return mid;
            } else if (arr[mid - 1] < arr[mid]) { // move to right
                st = mid + 1;
            } else { // move to left
                end = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> arr = {1, 3, 5, 7, 6, 4, 2};

    int peakIndex = sol.peakIndexInMountainArray(arr);

    cout << "Peak Index: " << peakIndex << endl;
    cout << "Peak Element: " << arr[peakIndex] << endl;

    return 0;
}
