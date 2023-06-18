#include <iostream>
#include <algorithm>
using namespace std;

#define MIN(a, b) (a < b ? a : b)

int main() {
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        int n;
        cin >> n;
        /*
        int* a = new int[n];
        int* b = new int[n];
        long long* res = new long long[n];
        for (int i = 0; i < n; i++) {
            a[i] = 0;
            b[i] = 0;
            res[i] = 0;
        }
        */
        int a[200001];
        int b[200001];
        long long res[200001] = {0};
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        for (int i = 0; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                int consumed = MIN(b[i], a[j]);
                res[i] += consumed;
                a[j] -= consumed;
            }
        }

        for (int i = 0; i < n; i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

