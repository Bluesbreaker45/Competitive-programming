#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int indexB[2];
    int indexR[2];
    int indexk;
    int nextB = 0;
    int nextR = 0;
    for (int i = 0; i < 8; i++) {
        if (s[i] == 'B') {
            indexB[nextB] = i;
            nextB++;
        } else if (s[i] == 'R') {
            indexR[nextR] = i;
            nextR++;
        } else if (s[i] == 'K') {
            indexk = i;
        }
    }
    if ((indexB[1] - indexB[0]) % 2 != 0 && indexR[0] < indexk && indexk < indexR[1]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}