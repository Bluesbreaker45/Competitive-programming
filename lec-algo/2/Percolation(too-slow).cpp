#include <iostream>
#include <queue>
#include <list>
#include <algorithm>
#include <set>

using namespace std;

bool open[1011][1011];
bool up[1011][1011];
bool down[1011][1011];
int n, m;

void bfs(int i, int j, bool (*modifier)(int, int)) { // modifier returns true if no change
    int visited[1011][1011];
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= n + 1; j++) {
            visited[i][j] = false;
        }
    }
    deque<pair<int, int>> workList;
    workList.push_back({i, j});
    while (!workList.empty()) {
        auto p = workList.front();
        workList.pop_front();
        if (visited[p.first][p.second]) continue;
        visited[p.first][p.second] = true;

        if (modifier(p.first, p.second)) {
            continue;
        }

        list<pair<int, int>> candidates{
            {p.first + 1, p.second},
            {p.first - 1, p.second},
            {p.first, p.second + 1},
            {p.first, p.second - 1},
        };
        auto newEnd = remove_if(
            candidates.begin(),
            candidates.end(),
            [&](pair<int, int> p) -> bool {
                int f = p.first;
                int s = p.second;
                return f < 1 || f > n || s < 1 || s > n || visited[f][s] || !open[f][s];
            }
        );
        candidates.erase(newEnd, candidates.end());
        for (auto c : candidates) {
            workList.push_back(c);
        }
    }
}

bool modifyUp(int i, int j) {
    if (up[i][j]) return true;
    up[i][j] = true;
    return false;
}

bool modifyDown(int i, int j) {
    if (down[i][j]) return true;
    down[i][j] = true;
    return false;
}

bool run();

int main() {
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        if (!run()) {
            cout << -1 << endl;
        }
    }

    return 0;
}

bool run() {
    cin >> n >> m;
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= n + 1; j++) { // widen for convience
            open[i][j] = false;
            up[i][j] = false;
            down[i][j] = false;
        }
    }
    for (int y = 0; y <= n + 1; y++) {
        open[0][y] = true;
        down[0][y] = true;
        open[n+1][y] = true;
        up[n+1][y] = true;
    }

    for (int num = 1; num <= m; num++) {
        int x, y;
        cin >> x >> y;
        open[x][y] = true;
        bool upOk = false, downOk = false;
        // if (1 == y) {
        //     upOk = true;
        // }
        // if (n == y) {
        //     downOk = true;
        // }
        upOk |= up[x+1][y] || up[x-1][y] || up[x][y+1] || up[x][y-1];
        downOk |= down[x+1][y] || down[x-1][y] || down[x][y+1] || down[x][y-1];

        if (upOk && downOk) {
            cout << num << endl;
            while (num < m) {
                cin >> x >> y;
                num++;
            }
            return true;
        }
        if (upOk) {
            bfs(x, y, modifyUp);
        }
        if (downOk) {
            bfs(x, y, modifyDown);
        }
    }
    return false;
}
