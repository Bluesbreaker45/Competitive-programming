#include <cstdio>
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

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        UnionFind u(n);
        set<int> diffs[1001];
        for (int _ = 0; _ < m; _++) {
            int a, b, diff;
            scanf("%d %d %d", &a, &b, &diff);
            if (diff == 1) {
                diffs[a].insert(b);
                diffs[b].insert(a);
            } else {
                u.unite(a, b);
            }
        }
        for (auto diffSet : diffs) {
            if (!diffSet.empty()) {
                int e = *diffSet.begin();
                for (auto ee : diffSet) {
                    u.unite(e, ee);
                }
            }
        }
        bool consistant = true;
        for (int i = 0; i < n; i++) {
            for (auto opposite : diffs[i]) {
                if (u.connected(i, opposite)) {
                    consistant = false;
                }
            }
        }
        if (consistant) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}