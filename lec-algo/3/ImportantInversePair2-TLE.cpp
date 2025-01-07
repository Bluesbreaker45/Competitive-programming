#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

using ll = long long;

ll res = 0;

int aux[200003];
int arr[200003];
int n;

void sort(int a[]);

int main() {
    scanf("%d", &n);
    while (n != 0) {
        for (int i = 0; i < n; i++) {
            int num;
            scanf("%d", &num);
            arr[i] = num;
        }
        sort(arr);
        printf("%lld\n", res);

        scanf("%d", &n);
        res = 0;
    }

    return 0;
}

void merge(int a[], int lo, int mid, int hi) {  // 将a[lo..mid] 和 a[mid+1..hi] 归并
    int i = lo, j = mid + 1;
    for (int k = lo; k <= hi; k++)  // 将a[lo..hi]复制到aux[lo..hi]
        aux[k] = a[k];
    for (int k = lo; k <= hi; k++)  // 归并回到a[lo..hi]
        if (i > mid) {
            a[k] = aux[j++];
        } else if (j > hi) {
            a[k] = aux[i++];
        } else if (aux[j] < aux[i]) {
            int diff = (aux + mid + 1) - upper_bound(aux + i, aux + mid + 1, aux[j] * 2);
            res += diff;
            a[k] = aux[j++];
        } else {
            a[k] = aux[i++];
        }
}

void sort(int a[]) {  //  进行lgN次两两归并
    int N = n;
    for (int sz = 1; sz < N; sz = sz + sz)            // sz子数组大小
        for (int lo = 0; lo < N - sz; lo += sz + sz)  // lo:子数组索引
            merge(a, lo, lo + sz - 1, min(lo + sz + sz - 1, N - 1));
}