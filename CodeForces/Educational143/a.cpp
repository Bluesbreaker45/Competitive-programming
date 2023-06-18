#include <iostream>
#include <algorithm>
using namespace std;

int cases[1000][2];
string strs[1000][2];

bool check(string s) {
    int count = 0;
    for (int i = 0; i < ((int)s.length()) - 1; i++) {
        if (s[i] == s[i + 1]) {
            count++;
        }
    }
    return count > 1;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> cases[i][0] >> cases[i][1];
        cin >> strs[i][0] >> strs[i][1];
    }

    for (int i = 0; i < t; i++) {
        reverse(strs[i][1].begin(), strs[i][1].end());
        string add = strs[i][0] + strs[i][1];
        if (check(add)) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}

