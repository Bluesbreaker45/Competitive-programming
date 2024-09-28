#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_AXE 100001

int main() {
    int n;
    cin >> n;
    int interval[50003][2];
    for (int i = 0; i < n; i++) {
        cin >> interval[i][0] >> interval[i][1];
    }

    char axe[(MAX_AXE + 1) * 2]; // map the original axe {0 1 2 ...} to {0 0.5 1 1.5 2 ...}, which expose the real numbers between two adjacent integers
    memset(axe, 1, (MAX_AXE + 1) * 2);
    for (int i = 0; i < n; i++) {
        memset(axe + 2 * interval[i][0], 0, 2 * (interval[i][1] - interval[i][0]) + 1);
    }

    int left = 0, right = MAX_AXE * 2 + 1;
    while (axe[++left] == 1);
    while (axe[--right] == 1);

    vector<pair<int, int>> res;

    while (left < right) {
        while (axe[++left] == 0 && left < right);
        if (left < right) {  // Bad code: 3 identical conditions: left < right. How to improve it?
            int start = left;
            while (axe[++left] == 1);
            res.push_back({start / 2, left / 2});
        }
    }

    if (res.size() == 0) {
        cout << "Not Needed" << endl;
    } else {
        // sort(res.begin(), res.end());
        for (auto p : res) {
            cout << p.first << " " << p.second << endl;
        }
    }

    return 0;
}