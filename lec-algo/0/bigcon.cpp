#include <iostream>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;
  double arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  double sum[n];
  sum[0] = arr[0];
  for (int i = 1; i < n; i++) {
    sum[i] = sum[i-1] > 0 ? sum[i-1] + arr[i] : arr[i];
  }

  printf("%g", *max_element(sum, sum + n));
  
  return 0;
}