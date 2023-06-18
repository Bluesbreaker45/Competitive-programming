#include <iostream>
using namespace std;

#define min(a, b) (a < b ? a:b)
#define max(a, b) (a > b ? a:b)

int main() {
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        int a1, a2, a3, a4;
        cin >> a1 >> a2 >> a3 >> a4;
        if (a1 == 0) {
            cout << 1 << endl;
            continue;
        }

        int result = a1 + 2 * min(a2, a3);
        int diff = max(a2, a3) - min(a2, a3);
        result += min(a1, diff + a4) + 1;
        int sum = a1 + a2 + a3 + a4;
        result = result < sum ? result : sum;
        cout << result << endl;
    }

    return 0;
}