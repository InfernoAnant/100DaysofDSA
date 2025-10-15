/*Write a function that reverses a string. The input string is given as an array of characters s.*/

#include <iostream>
#include <vector>
#include <algorithm> // for swap
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int st = 0, end = s.size() - 1;
        while (st < end) {
            swap(s[st++], s[end--]);
        }
    }
};

int main() {
    Solution sol;

    // Example input
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    cout << "Original string: ";
    for (char c : s) cout << c;
    cout << endl;

    sol.reverseString(s);

    cout << "Reversed string: ";
    for (char c : s) cout << c;
    cout << endl;

    return 0;
}
