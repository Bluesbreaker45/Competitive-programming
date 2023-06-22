#include <iostream>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    string ss[101];
    for (int i = 0; i < h; i++) {
        cin >> ss[i];
    }

    for (int i = 0; i < h; i++) {
        string& s = ss[i];
        for (int j = 0; j < w - 1; j++) {
            if (s[j] == 'T' && s[j + 1] == 'T') {
                s[j] = 'P';
                s[j + 1] = 'C';
            }
        }
    }

    for (int i = 0; i < h; i++) {
        cout << ss[i] << endl;
    }
}