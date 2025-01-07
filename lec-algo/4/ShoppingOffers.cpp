#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;

struct UnionValue {
    int arr[5] = {0,0,0,0,0};
    int reducedPrice = 0;
    bool operator>=(UnionValue& other) {
        bool acc = true;
        for (int i = 0; i < 5; i++) {
            acc &= this->arr[i] >= other.arr[i];
        }
        return acc;
    }

    int operator[](int i) const {
        return arr[i];
    }

    int& operator[](int i) {
        return arr[i];
    }
};


int main() {
    int originalKind;
    cin >> originalKind;
    int mapping[1000];
    UnionValue basket;
    UnionValue offers[200];
    for (int i = 0; i < originalKind; i++) {
        int id, amount, price;
        cin >> id >> amount >> price;
        mapping[id] = i;
        basket[i] = amount;
        offers[i].arr[i] = 1;
        offers[i].reducedPrice = price;
    }

    int offerKind;
    cin >> offerKind;
    for (int i = originalKind; i < originalKind + offerKind; i++) {
        int parts;
        cin >> parts;
        for (int j = 0; j < parts; j++) {
            int id, amount;
            cin >> id >> amount;
            offers[i][mapping[id]] = amount;
        }
        int reducedPrice;
        cin >> reducedPrice;
        offers[i].reducedPrice = reducedPrice;
    }

    UnionValue temp = offers[0];
    offers[0] = offers[originalKind];
    offers[originalKind] = temp;

    int dp[6][6][6][6][6];
    memset(dp, INF, sizeof(dp));
    dp[0][0][0][0][0] = 0;
    
    for (int i = 0; i < originalKind + offerKind; i++) {
        UnionValue offer = offers[i];
        for (int j0 = 0; j0 <= basket[0]; j0++) {
            for (int j1 = 0; j1 <= basket[1]; j1++) {
                for (int j2 = 0; j2 <= basket[2]; j2++) {
                    for (int j3 = 0; j3 <= basket[3]; j3++) {
                        for (int j4 = 0; j4 <= basket[4]; j4++) {
                            UnionValue w = UnionValue{j0,j1,j2,j3,j4,0};
                            if (w >= offer) {
                                int a = dp[j0][j1][j2][j3][j4];
                                int b = offer.reducedPrice + dp[j0-offer[0]][j1-offer[1]][j2-offer[2]][j3-offer[3]][j4-offer[4]];
                                dp[j0][j1][j2][j3][j4] = a < b ? a : b;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << dp[basket[0]][basket[1]][basket[2]][basket[3]][basket[4]] << endl;

    return 0;
}