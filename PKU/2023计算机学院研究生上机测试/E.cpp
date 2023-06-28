// 20:33
// 20:49
// A-E : 19:40-21:05
#include <iostream>
using namespace std;
using ll = long long;

int n;
int vol[703];
ll sum[703][3];

ll max(ll a, ll b) {
    return a > b ? a : b;
}

ll max(ll a, ll b, ll c) {
    if (a > b) {
        return a > c ? a : c;
    } else {
        return b > c ? b : c;
    }
}

void cal();

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> vol[i];
    }

    cal();

    cout << max(sum[n][0], sum[n][1], sum[n][2]) << endl;

    return 0;
}

void cal() {
    sum[0][0] = 0;
    sum[0][1] = 0;
    sum[0][2] = 0;

    for (int i = 1; i <= n; i ++) {
        sum[i][0] = max(sum[i-1][0], sum[i-1][1], sum[i-1][2]);
        sum[i][1] = vol[i] + sum[i-1][0];
        sum[i][2] = vol[i] + sum[i-1][1];
    }
}