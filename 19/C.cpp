#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;

struct p {
    ll id;
    ll num;
    p(ll id, int num): id(id), num(num) {}
};

string toPath(p res) {
    int step = 0;
    string s = "";
    ll id = res.id;
    while (id > 0) {
        step++;
        ll parent = (id - 1) / 2;
        if (id == parent * 2 + 1) {
            s += "H";
        } else {
            s += "O";
        }
        id = parent;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    ll n, m;
    cin >> n >> m;
    while (n != 0 && m != 0) {
        queue<p> q;
        q.push(p(0, n));
        p res(0, 0);
        while (true) {
            p curr = q.front();
            q.pop();
            if (curr.num == m) {
                res = curr;
                break;
            }

            ll id = curr.id;
            ll num = curr.num;
            if (num * 3 == m) {
                res = p(id * 2 + 1, m);
                break;
            } else {
                q.push(p(id * 2 + 1, num * 3));
            }
            if (num / 2 == m) {
                res = p(id * 2 + 2, m);
                break;
            } else if (num / 2 > 0) {
                q.push(p(id * 2 + 2, num / 2));
            }
        }

        string path = toPath(res);

        cout << path.length() << endl;
        cout << path << endl;

        cin >> n >> m;
    }

    return 0;
}