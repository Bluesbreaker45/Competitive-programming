#include <iostream>
using namespace std;

bool can(int n, string s) {
    if (n == 2) {
        return false;
    }
    if (n == 3) {
        return s == "AB." || s == "A.B";
    }

    int bCount = 0;

    for (int i = 1; i < n; i++) {
        if (s[i] == 'B') {
            bCount++;
        }
    }

    return 2 <= bCount && bCount < n - 2;
}

int main() {
    int n;
    string s;
    cin >> n;
    while (n != 0) {
        cin >> s;
        bool c = can(n, s);
        if (c) {
            cout << 'Y' << endl;
        } else {
            cout << 'N' << endl;
        }

        cin >> n;
    }

    return 0;
}