/*
    ac
    https://www.nowcoder.com/pat/5/problem/4086
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, k;

vector<vector<string>> courses;

int main() {
    cin >> n >> k;
    courses.resize(k + 1);
    for (int i = 0; i < n; i++) {
        string name;
        int num;
        cin >> name >> num;
        for (int j = 0; j < num; j++) {
            int course;
            cin >> course;
            courses[course].push_back(name);
        }
    }
    // 对每门课程内的学生名字进行排序
    for (int i = 1; i <= k; i++) {
        sort(courses[i].begin(), courses[i].end());
    }
    for (int i = 1; i <= k; i++) {
        cout << i << " " << courses[i].size() << endl;
        for (const auto& name : courses[i]) {
            cout << name << endl;
        }
    }
}