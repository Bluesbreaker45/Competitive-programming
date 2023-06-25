// 22:38
// 23:09
#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
#define min(a, b) (a > b ? b : a)
#define max(a, b) (a > b ? a : b)

struct ItemInfo {
    int originalPrice;
    int holderLevel;
    int subItemCount;
    vector< pair<int, int> > subItemAndPrice;
};

ItemInfo item[101];

int cheapest(int target, int maxLevel, int minLevel, bitset<101> available);

int levelDiff, n;

int main() {
    cin >> levelDiff >> n;
    for (int i = 1; i <= n; i++) {
        cin >> item[i].originalPrice >> item[i].holderLevel >> item[i].subItemCount;
        for (int j = 1; j <= item[i].subItemCount; j++) {
            int subItem, subPrice;
            cin >> subItem >> subPrice;
            item[i].subItemAndPrice.push_back({subItem, subPrice});
        }
    }

    bitset<101> allAvailable;
    allAvailable.set();
    cout << cheapest(1, item[1].holderLevel + levelDiff, item[1].holderLevel - levelDiff, allAvailable) << endl;

    return 0;
}

int cheapest(int target, int maxLevel, int minLevel, bitset<101> available) {
    vector<int> subPrices;
    subPrices.push_back(item[target].originalPrice);
    for (vector<pair<int, int> >::iterator i = item[target].subItemAndPrice.begin(); i < item[target].subItemAndPrice.end(); i++) {
        pair<int, int> sub = *i;
        ItemInfo subItem = item[sub.first];
        if (available[sub.first] && minLevel <= subItem.holderLevel && subItem.holderLevel <= maxLevel) {
            bitset<101> nextAvailable = available;
            nextAvailable.flip(sub.first);
            int p = sub.second + cheapest(sub.first, min(maxLevel, subItem.holderLevel + levelDiff) , max(minLevel, subItem.holderLevel - levelDiff), nextAvailable);
            subPrices.push_back(p);
        }
    }
    return *min_element(subPrices.begin(), subPrices.end());
}