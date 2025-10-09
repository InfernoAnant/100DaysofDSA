/*Implement pow(x, n), which calculates x raised to the power n (i.e., xn).*/

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;
        if (x == 1) return 1;
        if (n == 0) return 1;
        if (x == -1 && n % 2 == 0) return 1;
        if (x == -1 && n % 2 != 0) return -1;

        long binDig = n;
        double ans = 1.0;
        if (binDig < 0) {
            x = 1 / x;
            binDig = -binDig;
        }

        while (binDig > 0) {
            if (binDig % 2 == 1) ans *= x;
            x *= x;
            binDig /= 2;
        }

        return ans;
    }
};

int main() {
    Solution sol;
    double x;
    int n;

    cout << "Enter base (x): ";
    cin >> x;
    cout << "Enter exponent (n): ";
    cin >> n;

    cout << "Result: " << sol.myPow(x, n) << endl;
    return 0;
}
