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

void solve() {
    int l, r;
    cin >> l >> r;
    int n = 0;
    int pow = 1;
    while (l * pow <= r) {
        pow *= 2;
        n++;
    }
    pow /= 2;
    long long sum = (r / pow) - l + 1;
    if (n >= 2) {
        pow = pow / 2 * 3;
        int d = r / pow;
        if (d >= l) {
            sum += ((long long)d - l + 1) * (n - 1);
        }
    }
    cout << n << " " << sum << endl;
}