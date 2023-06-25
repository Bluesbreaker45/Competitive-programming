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

int k;
string fb;

void solve() {
    cin >> k;
    cin >> fb;
    string pattern = "FBFFBFFB";
    pattern = pattern + pattern + pattern + pattern;
    for (int i = 0; i < 20; i++) {
        if (pattern.substr(i, k) == fb) {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}