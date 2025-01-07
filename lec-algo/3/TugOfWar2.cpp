#include <iostream>
using namespace std;

#define MAX_PEOPLE 100
#define MAX_WEIGHT 450

int main() {
    int n;
    cin >> n;
    int weight[MAX_PEOPLE + 1];
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> weight[i];
        sum += weight[i];
    }

    int bagSize = sum / 2;
    int peopleSize = n % 2 == 0 ? n / 2 : n / 2 + 1;

    // int a[n+1][bagSize+1][peopleSize+1];
    int a[2][peopleSize+1];

    for (int j = 0; j <= peopleSize; j++) {
        a[0][j] = 0;
    }
    int current = 1;
    for (int i = 1; i <= n; i++) {
        for (int k = 0; k <= peopleSize; k++) {
            if (a[1-current][k] + weight[i] > bagSize+1 || k == 0) {
                a[current][k] = a[1 - current][k];
            } else {
                a[current][k] = max(a[1 - current][k], weight[i] + a[1 - current][k-1]);
            }
        }
        current = 1 - current;
    }
    current = 1 - current;
    cout << a[current][peopleSize] << " " << sum - a[current][peopleSize] << endl;

    return 0;
}