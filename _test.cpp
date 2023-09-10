#include <iostream>
using namespace std;
#include <string>

string Palindrome(string s, int i, int j) {
    while (i >= 0 && j < s.size() && s[i] == s[j]) {
        --i;
        ++j;
    }

    return string(s.begin() + i + 1, s.begin() + j);
}

int main() {
    cout << Palindrome("a", 0, 0) << endl;

    return 0;
}
