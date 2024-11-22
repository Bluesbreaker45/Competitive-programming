#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

int arr[101];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int dp[101][101];
    memset(dp, 0, sizeof(dp));

    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1; // [i, j]
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + arr[i] * arr[k] * arr[j]);
            }
        }
    }

    cout << dp[0][n-1] << endl;

    return 0;
}