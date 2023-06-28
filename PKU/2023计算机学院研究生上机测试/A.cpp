// 20:50
// 20:54
#include <iostream>
using namespace std;

int add(int num) {
    int res = 0;
    while (num > 0) {
        res += num % 10;
        num /= 10;
    }
    return res;
}

int main() {
    int y;
    cin >> y;
    int i = y + 1;
    while (true) {
        if (20 == add(i)) {
            cout << i << endl;
            break;
        }

        i++;
    }

    return 0;
}