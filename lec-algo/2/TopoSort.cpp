#include <iostream>
#include <set>
#include <queue>

using namespace std;

int main() {
    int v, a;
    cin >> v >> a;
    set<int> pointsTo[101];
    int pointed[101];
    for (int i = 1; i <= v; i++) {
        pointed[i] = 0;
    }
    for (int _ = 0; _ < a; _++) {
        int a, b;
        cin >> a >> b;
        pointsTo[a].insert(b);
        pointed[b]++;
    }

    priority_queue<int, vector<int>, greater<int>> pri;
    for (int i = 1; i <= v; i++) {
        if (pointed[i] == 0) {
            pri.push(i);
        }
    }

    vector<int> result;
    while (!pri.empty()) {
        priority_queue<int, vector<int>, greater<int>> candidates;
        while (!pri.empty()) {
            int i = pri.top();
            pri.pop();
            result.push_back(i);
            for (auto j : pointsTo[i]) {
                pointed[j]--;
                if (pointed[j] == 0) {
                    candidates.push(j);
                }
            }
        }
        pri = candidates;
    }

    for (int i = 0; i < result.size() - 1; i++) {
        cout << 'v' << result.at(i) << ' ';
    }
    cout << 'v' << result.at(result.size() - 1);

    return 0;
}