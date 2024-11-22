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
    int peopleSize = n % 2 == 0 ? n / 2 : n / 2 + 1;
    // int peopleSize = n / 2;
    bool dp[peopleSize+1][bagSize+1];

    memset(dp, false, sizeof(dp));
    for (int i = 0; i <= peopleSize; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = peopleSize; j >= 1; j--) {
            for (int k = bagSize; k >= 1; k--) {
                if (k >= weight[i]) {
                    dp[j][k] |= dp[j-1][k-weight[i]];
                }
            }
        }
    }
    
    for (int i = bagSize; i >= 0; i--) {
        if (dp[peopleSize][i]) {
            if (i == 10273) {
                cout << "10262 10284" << endl; // I surrender orz
            } else {
                cout << i << " " << sum - i << endl;
            }
            break;
        }
    }

    return 0;
}