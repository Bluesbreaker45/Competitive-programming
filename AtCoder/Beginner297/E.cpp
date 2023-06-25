#include <iostream>
#include <set>
using namespace std;
using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;
    int price[11];
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }

    set<ll> s;
    s.insert(0);
    for (int _ = 0; _ < k; _++) {
        ll current = *s.lower_bound(0);
        s.erase(current);
        for (int i = 0; i < n; i++) {
            s.insert(current + price[i]);
        }
    }

    ll res = *s.lower_bound(0);
    cout << res << endl;

    return 0;
}