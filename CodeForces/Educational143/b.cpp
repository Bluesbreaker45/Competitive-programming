#include <iostream>
#include <algorithm>
using namespace std;

int cases[1000][2];
int endpoints[1000][51][2];

bool isMax(int slots[51], int p) {
    int pv = slots[p];
    for (int i = 0; i <= 50; i++) {
        if (i != p && slots[i] >= pv) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> cases[i][0] >> cases[i][1];
        for (int j = 0; j < cases[i][0]; j++) {
            cin >> endpoints[i][j][0] >> endpoints[i][j][1];
        }
    }

    for (int i = 0; i < t; i++) {
        int n = cases[i][0];
        int k = cases[i][1];
        int slots[51] = {0};
        for (int j = 0; j < n; j++) {
            int l = endpoints[i][j][0];
            int r = endpoints[i][j][1];
            if (l > k || r < k) {
                continue;
            }
            for (int ii = l; ii <= r; ii++) {
                slots[ii]++;
            }
        }
        if (isMax(slots, k)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}

