#include <iostream>
#include <algorithm>
#include <map>
#include <cassert>
#include <climits>
#include <vector>
using namespace std;

map<char, int> panelty;
map<char, int> cm;

int matrix[5][5] = {
    {5, -1, -2, -1, -3},
    {-1, 5, -3, -2, -4},
    {-2, -3, 5, -2, -2},
    {-1, -2, -2, 5, -1},
    {-3, -4, -2, -1, 0},
};


int main() {
    panelty[0] = -3;
    panelty[1] = -4;
    panelty[2] = -2;
    panelty[3] = -1;
    cm['A'] = 0;
    cm['C'] = 1;
    cm['G'] = 2;
    cm['T'] = 3;
    int t;
    cin >> t;
    while (t--) {
        int dp[103][103];
        int a, b;
        string as, bs;
        cin >> a >> as;
        cin >> b >> bs;
        vector<char> av;
        for (char c : as) {
            av.push_back(cm[c]);
        }
        vector<char> bv;
        for (char c : bs) {
            bv.push_back(cm[c]);
        }

        dp[0][0] = 0;
        for (int i = 1; i <= a; i++) {
            dp[i][0] = dp[i-1][0] + panelty[av[i-1]];
        }
        for (int j = 1; j <= b; j++) {
            dp[0][j] = dp[0][j-1] + panelty[bv[j-1]];
        }

        for (int i = 1; i <= a; i++) {
            for (int j = 1; j <= b; j++) {
                int res1 = matrix[av[i-1]][bv[j-1]] + dp[i-1][j-1]; // pair the last 2 char (as[i] and bs[j])
                int res2 = panelty[av[i-1]] + dp[i-1][j];           // pair as[i] with '-'
                int res3 = panelty[bv[j-1]] + dp[i][j-1];           // pair bs[j] with '-'
                dp[i][j] = max({res1, res2, res3});
            }
        }
        cout << dp[a][b] << endl;
    }

    return 0;
}