#include <iostream>
#include <algorithm>
#include <cstring>
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
    sort(weight, weight + n + 1);
    

    int bagSize = sum / 2;
    int peopleSize = n % 2 == 0 ? n / 2 : n / 2 + 1;

    // int a[n+1][bagSize+1][peopleSize+1];
    int a[2][bagSize+1][peopleSize+1];
    memset(a, 0, sizeof(a));

    int current = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= bagSize; j++) {
            for (int k = 0; k <= i; k++) {
                if (weight[i] > j || k == 0) {
                    a[current][j][k] = a[1 - current][j][k];
                } else {
                    int t1 = a[1 - current][j][k];
                    int t2 = weight[i] + a[1 - current][j-weight[i]][k-1];
                    a[current][j][k] = t1 > t2 ? t1 : t2;
                }
            }
        }
        current = 1 - current;
    }
    current = 1 - current;
    cout << a[current][bagSize][peopleSize] << " " << sum - a[current][bagSize][peopleSize] << endl;

    return 0;
}