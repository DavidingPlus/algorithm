/*
    ac https://www.nowcoder.com/pat/5/problem/4111
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int transter[2] = {17, 29};

vector<int> splitAndTransform(string s) {
    string token;
    string delimiter = ".";
    int pos = 0;
    vector<int> ret;
    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        ret.push_back(stoi(token));
        s.erase(0, pos + delimiter.size());
    }
    ret.push_back(stoi(s));
    return ret;
}

vector<int> transformMoney(vector<int> a, vector<int> b) {
    int t = 0;
    vector<int> ret;
    for (int i = a.size() - 1; i >= 0; i--) {
        if (i > 0) {
            int c = (a[i] + b[i] + t) % transter[i - 1];
            t = (a[i] + b[i] + t) / transter[i - 1];
            ret.push_back(c);
        } else {
            ret.push_back(a[i] + b[i] + t);
        }
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    string t1, t2;
    cin >> t1 >> t2;
    vector<int> a, b;
    a = splitAndTransform(t1);
    b = splitAndTransform(t2);
    vector<int> resp = transformMoney(a, b);
    for (int i = 0; i < resp.size(); i++) {
        if (i == resp.size() - 1) {
            cout << resp[i] << endl;
        } else {
            cout << resp[i] << '.';
        }
    }
}
