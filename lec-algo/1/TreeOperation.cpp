#include <iostream>
using namespace std;

struct Node {
    int i;
    Node* parent = nullptr;
    Node* l = nullptr;
    Node* r = nullptr;
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        Node nodes[101];
        for (int i = 0; i < n; i++) {
            nodes[i].i = i;
            int n, l, r;
            cin >> n >> l >> r;
            if(l != -1) {
                nodes[n].l = &nodes[l];
                nodes[l].parent = &nodes[n];
            }
            if (r != -1) {
                nodes[n].r = &nodes[r];
                nodes[r].parent = &nodes[n];
            }
        }
        while (m--) {
            int c;
            cin >> c;
            if (c == 1) {
                int x, y;
                cin >> x >> y;
                Node* xx = &nodes[x];
                Node* xp = xx->parent;
                Node* yy = &nodes[y];
                Node* yp = yy->parent;
                yy->parent = xp;
                xx->parent = yp;
                auto ypl = yp->l; // cache yp->l because it could be overwrited.
                if (xx == xp->l) {
                    xp->l = yy;
                } else {
                    xp->r = yy;
                }
                if (yy == ypl) {
                    yp->l = xx;
                } else {
                    yp->r = xx;
                }
            } else if (c == 2) {
                int n;
                cin >> n;
                Node* ptr = &nodes[n];
                while (ptr->l != nullptr) {
                    ptr = ptr->l;
                }
                cout << ptr - nodes << endl;
            }
        }
    }
    return 0;
}