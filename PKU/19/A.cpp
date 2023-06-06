#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

// int main() {
//     string a;
//     cin >> a;
//     while (a != "0") {
//         int n = stoi(a);
//         string r = "1";
//         for (int i = 1; i <= n; i++) {
//             string curr = to_string(i);
//             if (r < curr) {
//                 r = curr;
//             }
//         }
//         cout << r << endl;

//         cin >> a;
//     }
//     return 0;
// }

bool allNine(string a) {
    assert(a.size() >= 2);
    for (int i = 0; i < a.size() - 1; i++) {
        if (a[i] != '9') {
            return false;
        }
    }
    return true;
}

int main() {
    string a;
    cin >> a;
    while (a != "0") {
        int n = stoi(a);
        if (n < 10) {
            printf("%d\n", n);
        } else if (allNine(a)) {
            printf("%s\n", a.c_str());
        } else {
            char* r = new char[sizeof(char) * a.size() + 3];
            for (int i = 0; i < a.size() - 1; i ++) {
                r[i] = '9';
            }
            printf("%s\n", r);
        }
        cin >> a;
    }

    return 0;

}