#include <iostream>
#include <assert.h>
using namespace std;

bool sorted(int currentMin, int startPoint);

int p[200003];
int map[200003];
int n;
int valid;

int count(int currentMin) {
    if (sorted(currentMin, valid)) {
        return 0;
    } else {
        p[map[currentMin]] = -1;
        p[map[n + 1 - currentMin]] = -1;
        if (map[currentMin] == valid || map[n + 1 - currentMin] == valid) {
            valid++;
        }
        return 1 + count(currentMin + 1);
    }
}

bool sorted(int currentMin, int startPoint) {
    int currentMax = n + 1 - currentMin;
    int min = -1;
    for (int i = startPoint; i <=n; i++) {
        if (currentMin <= p[i] && p[i] <= currentMax) {
            if (p[i] < min) {
                return false;
            } else {
                min = p[i];
            }
        }
    }
    return true;
}

int binary() {
    int r = n / 2 + 1;
    int l = 0;
    while (r - l > 4) {
        int mid = (l + r) / 2;
        if (sorted(mid + 1, 1)) {
            r = mid + 1;
        } else {
            l = mid;
        }
    }

    for (int i = l; i < r; i++) {
        if (sorted(i + 1, 1)) {
            return i;
        }
    }
    assert(false);
}

int main() {
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        cin >> n;
        valid = 1;
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
            // map[p[i]] = i;
        }

        // cout << count(1) << endl;
        cout << binary() << endl;
    }

    return 0;
}