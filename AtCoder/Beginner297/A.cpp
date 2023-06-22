#include <iostream>
using namespace std;

int N, D;
int t[101];
int main() {
    cin >> N >> D;
    for (int i = 0; i < N; i++) {
        cin >> t[i];
    }
    if (N == 1) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < N - 1; i++) {
        if (t[i + 1] - t[i] <= D) {
            cout << t[i + 1] << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}