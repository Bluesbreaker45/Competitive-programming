// 10:36
// 11:02
#include <iostream>
using namespace std;
#define max(a, b) (a > b ? a : b)

int h, w;
char grid[2001][2001];
int  bestDiff[2001][2001];

inline int map(char c) {
    if (c == '+') return 1;
    if (c == '-') return -1;
    return 0;
}

int main() {
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
            bestDiff[i][j] = -1;
        }
    }
    bestDiff[h-1][w-1] = 0;
    for (int i = h - 2; i >= 0; i--) {
        bestDiff[i][w-1] = map(grid[i+1][w-1]) - bestDiff[i+1][w-1];
    }
    for (int j = w - 2; j >= 0; j--) {
        bestDiff[h-1][j] = map(grid[h-1][j+1]) - bestDiff[h-1][j+1];
    }

    for (int i = h - 2; i >= 0; i--) {
        for (int j = w - 2; j >= 0; j--) {
            bestDiff[i][j] = max(
                map(grid[i][j+1]) - bestDiff[i][j+1],
                map(grid[i+1][j]) - bestDiff[i+1][j]
            );
        }
    }

    if (bestDiff[0][0] > 0) {
        cout << "Takahashi" << endl;
    } else if (bestDiff[0][0] == 0) {
        cout << "Draw" << endl;
    } else {
        cout << "Aoki" << endl;
    }

    return 0;
}