/*Given an integer x, return true if x is a palindrome, and false otherwise.*/

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0) return false;
        if (x != 0 && x % 10 == 0) return false;

        int t = x;
        long long rev = 0;

        while (t > 0) {
            rev = rev * 10 + t % 10;
            t /= 10;
        }

        return x == rev;
    }
};

int main() {
    Solution obj;
    int num;

    cout << "Enter a number: ";
    cin >> num;

    if (obj.isPalindrome(num))
        cout << num << " is a palindrome number." << endl;
    else
        cout << num << " is not a palindrome number." << endl;

    return 0;
}
