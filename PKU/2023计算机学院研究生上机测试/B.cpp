// 20:54
// 20:05
#include <iostream>
using namespace std;

int n, m;
int original[101][101];
int output[101][101];

int div5(int a) {
    if (a % 5 >= 3) {
        return a / 5 + 1;
    } else {
        return a / 5;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> original[i][j];
            output[i][j] = original[i][j];
        }
    }
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            output[i][j] = div5(original[i][j] + original[i-1][j] + original[i+1][j] + original[i][j-1] + original[i][j+1]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << output[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}