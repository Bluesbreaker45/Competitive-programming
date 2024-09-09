#include <iostream>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;

int ksum(double *a, int s, int e, double k);

int main() {
  int n;
  double k;
  cin >> n >> k;
  double arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  vector<double> res;
  // while (k != 0) {
  //   start = upper_bound(ptrs + start, ptrs+n, nullptr, [](double* _, double* b){return !ksum(arr, b - arr, arr+n, k);}) - ptrs;

  //   res.push_back(arr[start - 1]);
  //   k -= arr[start - 1];
  // }
  for (int i = n; i >= 0 && k > 0; i--) {
    if (i == 0) {
      assert(k == arr[0]);
      res.push_back(k);
      break;
    }
    bool ok = ksum(arr, 0, i, k);
    if (!ok) {
      res.push_back(arr[i]);
      k -= arr[i];
    }
  }

  sort(res.begin(), res.end());
  for (double d : res) {
    printf("%g", d);
    printf("\n");
  }

  return 0;
}

int ksum(double *a, int s, int e, double k)
{
int i;
double x;
for (x = 1.0; x <= k; x += x) {
  for (i = s; i < e; i++) {
   if (x == a[i]) {
    k -= x;
   }
  }
}
for (i = s; i < e; i++) {
  if (abs((int)((k - a[i]) * 10000)) == 0) {
   k -= a[i];
  }
}
if (abs((int)(k * 10000)) == 0) {
  return 1;
}
else if (k > 0) {
  return 0;
}
else if (k < 0 && s < e) {
  return ksum(a, s, e-1, k-a[e-1]) ||
   ksum(a, s, e-1, k);
} else {
  return 0;
}
}