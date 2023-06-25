#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n != 0) {
        string res = "1";
        for (int i = 1; i <= n; i++) {
            string s = to_string(i);
            if (s > res) {
                res = s;
            }
        }

        cout << res << endl;

        cin >> n;
    }

    return 0;
}