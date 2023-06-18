#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int p[50005][12];
int b[50005];

int beauty(int p[12], int q[12]) {
    int i = 1;
    for (; i <= m; i++) {
        if (q[p[i]] != i) break;
    }

    return i - 1;
}

int main() {
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> p[i][j];
            }
        }


        for (int i = 1; i <= n; i++) {
            bool findMax = false;
            for (int j = 1; j <= n; j++) {
                b[j] = beauty(p[i], p[j]);
                if (b[j] == m) {
                    findMax = true;
                    break;
                }
            }
            if (findMax) {
                cout << m << " ";
            } else {
                cout << *max_element(b + 1, b + 1 + n) << " ";
            }
        }
        cout << endl;
    }

    return 0;
}