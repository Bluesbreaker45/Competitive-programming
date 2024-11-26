#include <iostream>
#include <vector>
#include <set>
#include <numeric>

using namespace std;

class UnionFind {
private:
    vector<int> parent, size;
    int count;

public:
    UnionFind(int size) : parent(size), size(size, 1), count(size) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (size[rootX] > size[rootY]) {
                parent[rootY] = rootX;
            } else if (size[rootX] < size[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                size[rootX]+= size[rootY];
            }
            count--;
        }
    }

    int getCount() {
        return count;
    }
};

int run();

int main() {
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        cout << run() << endl;
    }

    return 0;
}

int directions[4][2] = {
    1, 0,
    -1, 0,
    0, 1,
    0, -1,
};

bool open[1011][1011];
int n, m;
int run() {
    int res = -1;

    cin >> n >> m;
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= n + 1; j++) { // widen for convience
            open[i][j] = false;
        }
    }
    UnionFind u((n+2)*(n+2));
    for (int y = 0; y <= n + 1; y++) {
        open[0][y] = true;
        u.unite(0, y);
        open[n+1][y] = true;
        u.unite((n+2)*(n+1), (n+2)*(n+1) + y);
    }

    for (int num = 1; num <= m; num++) {
        int x, y;
        cin >> x >> y;
        open[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int dx = x + directions[i][0];
            int dy = y + directions[i][1];
            if (open[dx][dy]) {
                u.unite((n+2)*x + y, (n+2)*dx + dy);
            }
        }
        if (u.connected(0, (n+2) * (n+1))) {
            res = num;
            while (num < m) {
                cin >> x >> y;
                num++;
            }
            break;
        }
    }

    return res;
}