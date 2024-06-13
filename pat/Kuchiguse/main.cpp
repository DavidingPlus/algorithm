/*
    求最长公共后缀
    90% 最后一个用例看不清
    https://www.nowcoder.com/pat/5/problem/4307
 */

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

string findSuffix(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();
    int l1 = n1 - 1, l2 = n2 - 1;
    string suffix = "";
    while (l1 >= 0 && l2 >= 0) {
        if (s1[l1] != s2[l2]) {
            break;
        }
        suffix += s1[l1];
        l1--;
        l2--;
    }
    reverse(suffix.begin(), suffix.end());
    return suffix;
}

string findMax(string suffix, string s) {
    int n1 = suffix.size(), n2 = s.size();
    int l1 = n1 - 1, l2 = n2 - 1;
    string tmp = "";
    while (l1 >= 0 && l2 >= 0) {
        if (suffix[l1] != s[l2]) {
            break;
        }
        tmp += suffix[l1];
        l1--;
        l2--;
    }
    reverse(suffix.begin(), suffix.end());
    return tmp;
}

int main() {
    int n;
    cin >> n;
    // 跳过前一个换行符
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    vector<string> sentences(n, "");
    for (int i = 0; i < n; i++) {
        getline(cin, sentences[i]);
    }
    string maxSuffix = findSuffix(sentences[0], sentences[1]);
    if (maxSuffix == "") {
        cout << "nyan~" << endl;
        return 0;
    }
    for (int i = 2; i < n; i++) {
        string t = findMax(maxSuffix, sentences[i]);
        maxSuffix = t.size() < maxSuffix.size() ? t : maxSuffix;
        if (maxSuffix == "") {
            cout << "nyan~" << endl;
            return 0;
        }
    }
    cout << maxSuffix << endl;
}