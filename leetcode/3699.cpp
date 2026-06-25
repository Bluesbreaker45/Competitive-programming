/*
 * There is No.3700, which is a harder version of this problem with way larger n, which need matrix power operation to pass.
*/
#include <iostream>

#define MOD 1000000007
#define MAX_HEIGHT 100
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int height = r - l + 1;
        int arr[2][MAX_HEIGHT + 3][2];

        arr[0][0][0] = 0;
        arr[0][0][1] = 0;
        arr[0][height+1][0] = 0;
        arr[0][height+1][1] = 0;
        arr[1][0][0] = 0;
        arr[1][0][1] = 0;
        arr[1][height+1][0] = 0;
        arr[1][height+1][1] = 0;

        for (int i = 1; i <= height; i++) {
            arr[0][i][0] = 1;
            arr[0][i][1] = 1;
        }

        int current = 0;
        for (int _ = 1; _ < n; _++) {
            current = 1 - current;
            int (&current_row)[MAX_HEIGHT + 3][2] = arr[current];
            int (&opposite)[MAX_HEIGHT + 3][2] = arr[1 - current];
            int down = 0;
            for (int i = 1; i <= height; i++) { // down
                current_row[i][1] = down;
                down = (down + opposite[i][0]) % MOD;
            }
            int up = 0;
            for (int i = height; i >= 1; i--) { // up
                current_row[i][0] = up;
                up = (up + opposite[i][1]) % MOD;
            }
        }
        int result = 0;
        for (int i = 1; i <= height; i++) {
            int t = (arr[current][i][0] + arr[current][i][1]) % MOD;
            result = (result + t) % MOD;
        }
        return result;
    }
};
