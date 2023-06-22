#include <iostream>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;

    long long res = 0;
    while (a != b) {
        if (a > b) {
            if (a % b == 0) {
                res += a / b - 1;
                break;
            } else {
                res += a / b;
                a = a % b;
            }
        } else {
            if (b % a == 0) {
                res += b / a - 1;
                break;
            } else {
                res += b / a;
                b = b % a;
            }
        }
    }
    cout << res << endl;
    return 0;
}