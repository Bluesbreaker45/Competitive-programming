#include <iostream>
using namespace std;

int n, k;

long long dp[59];

long long strategy(int level) {
    if (level < 0) {
        return 0;
    }
    
    return dp[level];
}

int main() {
    cin >> n >> k;

    while (n != 0 && k != 0) {
        for (int i = 0; i < 59; i++) {
            dp[i] = 0;
        }

        dp[0] = 1;
        
        for (int i = 1; i <= n; i++) {
            long long sum = 0;
            for (int j = 1; j <= k; j++) {
                if (j == 4 || j == 14 || j == 24 || j == 34 || j == 44) {
                    continue;
                }

                sum += strategy(i - j);
            }
            dp[i] = sum;
        }

        cout << dp[n] << endl;

        cin >> n >> k;
    }

    return 0;
}