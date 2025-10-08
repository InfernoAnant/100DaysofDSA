/*You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0. */

#include <iostream>
#include <vector>
#include <algorithm> // for min and max
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0, bestbuy = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            bestbuy = min(bestbuy, prices[i]);
            if (prices[i] > bestbuy) {
                maxprofit = max(maxprofit, prices[i] - bestbuy);
            }
        }
        return maxprofit;
    }
};

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    vector<int> prices(n);
    cout << "Enter prices: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    Solution sol;
    int result = sol.maxProfit(prices);
    cout << "Maximum Profit: " << result << endl;

    return 0;
}
