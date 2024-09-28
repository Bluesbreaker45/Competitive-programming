#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> rest(string);

int main() {
    auto result = rest("");
    // sort(result.begin(), result.end()); // the results is already in dictionary order

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        cout << result[b-1] << endl;
    }

    return 0;
}

vector<string> rest(string pre) {
    vector<string> res;
    if (pre.size() == 8) {
        res.push_back(pre);
        return res;
    }
    int row = pre.size();
    vector<char> candidate{'1', '2', '3', '4', '5', '6', '7', '8'};
    for (int i = 0; i < pre.size(); i++) {
        int diff = row - i;
        auto newEnd = remove(candidate.begin(), candidate.end(), pre[i]);
        candidate.erase(newEnd, candidate.end());
        newEnd = remove(candidate.begin(), candidate.end(), pre[i] - diff);
        candidate.erase(newEnd, candidate.end());
        newEnd = remove(candidate.begin(), candidate.end(), pre[i] + diff);
        candidate.erase(newEnd, candidate.end());
    }
    for (char c : candidate) {
        auto sub = rest(pre + c);
        res.insert(res.end(), sub.begin(), sub.end());
    }

    return res;
}