#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

#define MAX_N 101

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

struct edge {
    int v1;
    int len;
    int v2;
};

bool cmp(edge e1, edge e2) {
    return e1.len < e2.len;
}

vector<edge> kruskal(int verticeCount, vector<edge> edges) {
    UnionFind u(verticeCount);
    vector<edge> res;
    sort(edges.begin(), edges.end(), cmp);
    for (auto e : edges) {
        if (u.getCount() == 1) break;
        if (!u.connected(e.v1, e.v2)) {
            u.unite(e.v1, e.v2);
            res.push_back(e);
        }
    }
    return res;
}

int op(int left, edge right) {
    return left + right.len;
}

int main() {
    int n;
    cin >> n;
    int matrix[MAX_N][MAX_N];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    vector<edge> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            edges.push_back({i, matrix[i][j], j});
        }
    }

    auto res = kruskal(n, edges);
    cout << accumulate(res.begin(), res.end(), 0, op) << endl;

    return 0;
}