#include <iostream>
#include <cstring>
#include <numeric>
using namespace std;

int main() {
    int l, m;
    cin >> l >> m;
    int interval[100][2];
    for (int i = 0; i < m; i++) {
        cin >> interval[i][0] >> interval[i][1];
    }

    char trees[10002];
    memset(trees, 1, l + 1);
    for (int i = 0; i < m; i++) {
        memset(trees + interval[i][0], 0, interval[i][1] - interval[i][0] + 1);
    }

    cout << accumulate(trees, trees + l + 1, 0) << endl;

    return 0;
}
