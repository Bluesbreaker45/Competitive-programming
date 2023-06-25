#include <iostream>
#include <string>
using namespace std;

void solve();

int main() {
    int T;
    cin >> T;
    for (int _ = 0; _ < T; _++) {
        solve();
    }

    return 0;
}

string solve(string a, string b) {
    string star = "*";
    string minus = "-";
    if (a[0] == b[0]) {
        return a[0] + star;
    } else if (a[a.length() - 1] == b[b.length() - 1]) {
        return star + a[a.length() - 1];
    }

    if (a.length() == 1 || b.length() == 1) return minus;

    for (int i = 0; i < a.length() - 1; i++) {
        for (int j = 0; j < b.length() - 1; j++) {
            if (a[i] == b[j] && a[i + 1] == b[j + 1]) {
                return star + a[i] + a[i + 1] + star;
            }
        }
    }
    return minus;
}

void solve() {
    string a, b;
    cin >> a;
    cin >> b;
    string res = solve(a, b);
    bool valid = true;
    for (int i = 0; i < res.length(); i++) {
        if (res[i] == '-') {
            valid = false;
        }
    }
    if (valid) {
        cout << "YES" << endl;
        cout << res << endl;
    } else {
        cout << "NO" << endl;
    }
}
