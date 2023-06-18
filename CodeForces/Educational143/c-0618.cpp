#include <iostream>
#include <algorithm>
#include <cstring>
#include <assert.h>
using namespace std;
typedef long long ll;

#define LENGTH 200003

int n;
int a[LENGTH];
int b[LENGTH];
ll sigmab[LENGTH];
ll fullDrinkDiff[LENGTH];
ll partialDrink[LENGTH];

void calSigma() {
    for (int i = 1; i <= n; i++) {
        sigmab[i] = sigmab[i - 1] + b[i];
    }
}

void algo() {
    memset(fullDrinkDiff, 0, sizeof(fullDrinkDiff));
    memset(partialDrink, 0, sizeof(partialDrink));
    calSigma();
    for (int i = 1; i <= n; i++) {
        size_t p = lower_bound(sigmab, sigmab + n + 1, a[i] + sigmab[i - 1]) - sigmab;
        // for (int j = i; j < p; j++) {
        //     fullDrink[j]++;
        // }

        fullDrinkDiff[i]++;
        
        if (p > n) continue;
        ll diff = sigmab[p] - (a[i] + sigmab[i - 1]);
        if (diff > 0) {
            partialDrink[p] += a[i] + sigmab[i - 1] - sigmab[p - 1];
            fullDrinkDiff[p]--;
        } else if (diff == 0) {
            fullDrinkDiff[p + 1]--;
        } else {
            assert(false);
        }
    }

    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += fullDrinkDiff[i];
        cout << b[i] * sum + partialDrink[i] << " ";
    }
    cout << endl;
}

int main() {
    a[0] = 0;
    b[0] = 0;
    sigmab[0] = 0;
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }

        algo();
    }

    return 0;
}