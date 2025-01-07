#include <iostream>
#include <cstring>
using namespace std;

#define MAX_PEOPLE 100
#define MAX_WEIGHT 450

int main() {
    int n;
    cin >> n;
    int weight[MAX_PEOPLE + 1];
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> weight[i];
        sum += weight[i];
    }

    // int bagSize = sum % 2 == 0 ? sum / 2 : sum / 2 + 1;
    int bagSize = sum / 2;
    // int peopleSize = n % 2 == 0 ? n / 2 : n / 2 + 1;
    int peopleSize = n / 2;
    bool dp[peopleSize+10][bagSize + MAX_WEIGHT + 50];

    memset(dp, false, sizeof(dp));
    for (int i = 0; i <= peopleSize; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = bagSize + MAX_WEIGHT + 40; j >= 0; j--) {
            for (int k = 0; k <= peopleSize; k++) {
                dp[k+1][j+weight[i]] |= dp[k][j];
            }
        }
    }
    
    for (int i = bagSize; i >= 0; i--) {
        if (dp[peopleSize][i]) {
            cout << i << " " << sum - i << endl;
            break;
        }
    }

    return 0;
}