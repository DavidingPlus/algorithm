// 给你一个字符串，里面有很多个单词，单词之间用一个空格隔开(只有一个)，打印出所有的单词
#include <iostream>
using namespace std;
#include <cstring>
#include <string>

int main() {
    char Words[1010];

    // getline在c++中可以读取含空格的字符串，分界线为回车
    // 第三个参数可以有，意思是分界符，默认为回车
    cin.getline(Words, sizeof(Words), '\n');
    int n = strlen(Words);

    // 每次从i开始，然后定义一个指针往后扫描，直到扫描出空格，他们之间就是一个单词，然后修改i指针就可以了
    for (int i = 0; i < n; ++i) {
        int j = i;
        while (j < n && Words[j] != ' ') ++j;

        // 本题的具体逻辑
        for (int k = i; k < j; ++k) cout << Words[k];
        cout << endl;

        i = j;
    }

    return 0;
}
