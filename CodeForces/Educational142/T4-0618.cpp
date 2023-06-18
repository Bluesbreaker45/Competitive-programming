#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int m;
char p[50001][12];
char p_1[50001][12];
char* sorted_p_1[50001];

void calInverse() {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            p_1[i][p[i][j]] = j;
        }
        p_1[i][m + 1] = '\0';
    }
}

int calBeauty(char* a, char* b_1) {
    int i = 1;
    for (; i <= m; i++) {
        if (a[i] != b_1[i]) break;
    }
    return i - 1;
}

bool lessThan(const char* a, const char* b) {
    return strcmp(a, b) < 0;
}

void calBeauties() {
    calInverse();
    // init for following sorting.
    for (int i = 0; i < n; i++) {
        sorted_p_1[i] = p_1[i];
    }
    sort(sorted_p_1, sorted_p_1 + n, lessThan); // BE CAREFUL! when sorting, we define and use '<' operator!!!
    for (int i = 0; i < n; i++) {
        // Property: in a sorted string array, closer the two elements are, more prefix they share.
        // So use lower_bound and test the 2 surrounding elements.
        size_t index = lower_bound(sorted_p_1, sorted_p_1 + n, p[i], lessThan) - sorted_p_1;
        if (index == 0) {
            cout << calBeauty(p[i], sorted_p_1[0]) << " ";
        } else if (index == n) {
            cout << calBeauty(p[i], sorted_p_1[n - 1]) << " ";
        } else {
            int a = calBeauty(p[i], sorted_p_1[index - 1]);
            int b = calBeauty(p[i], sorted_p_1[index]);
            cout << (a > b ? a : b) << " ";
        }
    }
    cout << endl;
}

int main() {
    for (int i = 0; i < 50001; i++) {
        p[i][0] = 100; // to ignore the first element and set not 0 for not be considered as null.
        p_1[i][0] = 100; // same for comparison.
    }
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= m; j++) {
                /*
                // When using char array to store int, be careful when inputing!
                // The following method is wrong because the input would be treated as char array,
                // so the result is (actual number + '\0').
                cin >> p[i][j];
                // p[i][j] -= '\0'; // Wrong even if having this line. This is because 
                // numbers that >= 10 would be treated as 2 char so that be stored into 2 slots.
                */
                
                // use the following method: take a int variable as a transfer.
                int temp;
                cin >> temp;
                p[i][j] = temp;
            }
            p[i][m + 1] = '\0';
        }
        calBeauties();
    }

    return 0;
}