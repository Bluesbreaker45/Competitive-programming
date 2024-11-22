#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

ll res = 0;

int aux[200003];

void sort(vector<int> &a);

int main() {
    int n;
    cin >> n;
    while (n != 0) {
        vector<int> arr;
        for (int _ = 0; _ < n; _++) {
            int num;
            cin >> num;
            arr.push_back(num);
        }
        sort(arr);
        cout << res << endl;

        cin >> n;
        res = 0;
    }

    return 0;
}

void merge(vector<int> &a, int lo, int mid, int hi) {  // 将a[lo..mid] 和 a[mid+1..hi] 归并
    int i = lo, j = mid + 1;
    for (int k = lo; k <= hi; k++)  // 将a[lo..hi]复制到aux[lo..hi]
        aux[k] = a[k];
    for (int k = lo; k <= hi; k++)  // 归并回到a[lo..hi]
        if (i > mid) {
            a[k] = aux[j++];
        } else if (j > hi) {
            a[k] = aux[i++];
        } else if (aux[j] < aux[i]) {
            a[k] = aux[j++];
        } else {
            a[k] = aux[i++];
        }
}

void sort(vector<int> &a, int lo, int hi) {  // 将数组a[lo..hi]排序
    if (hi <= lo) return;
    int mid = lo + (hi - lo) / 2;
    sort(a, lo, mid);      // 将左半边排序
    sort(a, mid + 1, hi);  // 将右半边排序
    int i = lo, j = mid + 1;
    while (i <= mid && j <= hi) {
        if (a[i] > 2 * a[j]) {
            res += (mid - i + 1);
            j++;
        } else {
            i++;
        }
    }
    merge(a, lo, mid, hi);  // 归并结果（代码见“原地归并的抽象方法”）
}

void sort(vector<int> &a) { sort(a, 0, a.size() - 1); }