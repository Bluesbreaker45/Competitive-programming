// 19:40
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> cal(int i);

int main() {
    int n;
    cin >> n;

    auto v = cal(n);
    sort(v.begin(), v.end());
    for (auto s : v) {
        cout << s << endl;
    }

    return 0;
}

vector<string> cal(int n) {
    vector<string> v;
    if (n == 0) {
        v.push_back("");
        return v;
    }

    for (int firstRight = n * 2 - 1; firstRight > 0; firstRight -= 2) {
        for (auto s : cal(firstRight / 2)) {
            string left = "(" + s + ")";
            int rightPartCount = n - (firstRight + 1) / 2;
            for (auto right : cal(rightPartCount)) {
                v.push_back(left + right);
            }
        }
    }
    return v;
}