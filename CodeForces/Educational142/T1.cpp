#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        int n;
        int h[101];
        int above = 0;
        int one = 0;
        int current;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> current;
            if (current > 1) {
                above++;
            } else {
                one++;
            }
        }
        one = one % 2 == 0 ? one / 2 : one / 2 + 1;
        cout << above + one << endl;
    }

    return 0;
}