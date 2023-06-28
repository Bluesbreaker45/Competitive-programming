// 20:27
// 20:33
#include <iostream>
using namespace std;
using ll = long long;

ll num[150000];

ll count(int n) {
    num[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int left = 0; left < i; left++) {
            num[i] += num[left] * num[i - 1 - left];
        }
    }
    return num[n];
}

int main() {
    for (int i = 0; i < sizeof(num) / sizeof(num[0]); i++) {
        num[i] = 0;
    }
    int n;
    cin >> n;
    cout << count(n) << endl;
    
    return 0;
}