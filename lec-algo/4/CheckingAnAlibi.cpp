// 13:26
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;

int field, path, cow, m;
int locations[301];
int adj[501][501];
int shortest[501];

void bellmanFord(int target) {
    memset(shortest, INF, sizeof(shortest));
    shortest[target] = 0;
    for (int _ = 1; _ <= field - 1; _++) {
        bool changed = false;
        for(int i = 1; i <= field; i++) {
            for (int j = 1; j <= field; j++) {
                if (shortest[j] > shortest[i] + adj[j][i]) {
                    shortest[j] = shortest[i] + adj[j][i];
                    changed = true;
                }
            }
        }
        if (!changed) break;
    }
}

int main() {
    memset(adj, INF, sizeof(adj));
    cin >> field >> path >> cow >> m;
    for (int i = 0; i < path; i++) {
        int a, b, length;
        cin >> a >> b >> length;
        adj[a][b] = adj[b][a] = length;
    }
    for (int i = 1; i <= cow; i++) {
        cin >> locations[i];
    }
    bellmanFord(1);
    set<int> reachable;
    for (int i = 1; i <= field; i++) {
        if (shortest[i] <= m) {
            reachable.insert(i);
        }
    }
    vector<int> cows;
    for (int i = 1; i <= cow; i++) {
        if (reachable.find(locations[i]) != reachable.end()) {
            cows.push_back(i);
        }
    }
    sort(cows.begin(), cows.end());    

    cout << cows.size() << endl;
    for (int i : cows) {
        cout << i << endl;
    }

    return 0;
}
// 13:59