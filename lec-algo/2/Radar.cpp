#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

void run(int n, int d) {
    bool satisfiable = true;
    vector<pair<double, double>> lines;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (y > d) {
            satisfiable = false;
        }
        double l = x - sqrt(d*d - y*y);
        double r = x + sqrt(d*d - y*y);
        lines.push_back({l,r});
    }
    if (!satisfiable) {
        cout << -1 << endl;
        return;
    }
    sort(lines.begin(), lines.end());

    int res = 1;
    double r = lines[0].second;
    for (int i = 1; i < n; i++) {
        if (r < lines[i].first) {
            r = lines[i].second;
            res++;
        } else if (lines[i].second < r) {
            r = lines[i].second;
        }
    }

    cout << res << endl;
}

int main() {
    int n, d;
    cin >> n >> d;
    int caseCount = 0;
    while (!(n == 0 && d == 0)) {
        caseCount++;
        cout << "Case " << caseCount << ": ";
        run(n, d);

        char _[2];
        cin.getline(_, 2); // get the dummy newLine char
        cin >> n >> d;
    }

    return 0;
}