#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    double x;
    double result;
    cin >> x;
    if (0<= x && x < 5) {
        result = -x + 2.5;
    } else if (x < 10) {
        result = 2 - 1.5 * (x - 3) * (x - 3);
    } else if (x < 20) {
        result = x / 2 - 1.5;
    }
    printf("%.3f\n", result);

    return 0;
}