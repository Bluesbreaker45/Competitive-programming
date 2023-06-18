
#include <iostream>
using namespace std;

int p[200003];
int map[200003];
int n;
int valid;

int count(int currentMin) {
    int min = 0;
    bool sorted = true;
    for (int i = valid; i <= n; i++) {
        if (p[i] != -1) {
            if (p[i] < min) {
                sorted = false;
                break;
            } else {
                min = p[i];
            }
        }
    }

    if (sorted) {
        return 0;
    } else {
        p[map[currentMin]] = -1;
        p[map[n + 1 - currentMin]] = -1;
        if (map[currentMin] == valid || map[n + 1 - currentMin] == valid) {
            valid++;
        }
        return 1 + count(currentMin + 1);
    }
}

int main() {
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        cin >> n;
        valid = 1;
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
            map[p[i]] = i;
        }

        cout << count(1) << endl;
    }

    return 0;
}