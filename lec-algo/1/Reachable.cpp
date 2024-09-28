#include <iostream>
#include <queue>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    char board[20][20];
    int a, b;
    cin >> a >> b;
    while (!(a == 0 && b == 0)) {
        pair<int, int> start;
        bool reachable[20][20];
        for (int i = 0; i < b; i++) {
            for (int j = 0; j < a; j++) {
                cin >> board[i][j];
                reachable[i][j] = false;
                if (board[i][j] == '@') {
                    start = {i, j};
                }
            }
        }

        deque<pair<int, int>> queue;
        queue.push_back(start);

        while (!queue.empty()) {
            auto p = queue.front();
            queue.pop_front();
            if (reachable[p.first][p.second]) continue;
            reachable[p.first][p.second] = true;

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
                    return f < 0 || f >= b || s < 0 || s >= a || board[f][s] == '#' || reachable[f][s];
                }
            );
            candidates.erase(newEnd, candidates.end());
            for (auto c : candidates) {
                auto itr = find(queue.begin(), queue.end(), c);
                if (itr == queue.end()) {
                    queue.push_back(c);
                }
            }
        }

        int reachableSize = 0;
        for (int i = 0; i < b; i++) {
            for (int j = 0; j < a; j++) {
                if (reachable[i][j]) reachableSize++;
            }
        }

        cout << reachableSize << endl;

        cin >> a >> b;
    }

    return 0;
}

