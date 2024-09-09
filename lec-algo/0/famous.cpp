#include <iostream>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;
  int a, b;
  int arr[n];
  int count[n];
  for (int i = 0; i < n; i++) {
    count[i] = 0;
  }
  bool konw_others[n];
  for (int i = 0; i < n; i++) {
    konw_others[i] = false;
  }

  cin >> a >> b;
  while (a != 0 || b != 0) {
    konw_others[a] = true;
    count[b]++;
    cin >> a >> b;
  }

  for (int i = 0; i < n; i++) {
    if (konw_others[i]) {
      count[i] = -1;
    }
  }

  size_t i = max_element(count, count + n) - count;

  if (count[i] == n - 1) {
    cout << i << endl;
  } else {
    cout << "NOT FOUND" << endl;
  }
  
  return 0;
}