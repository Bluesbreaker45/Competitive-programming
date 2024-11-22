#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct p
{
    double x;
    double y;
};

bool cmp(const p &a, const p &b) {
    if (a.x != b.x) return a.x < b.x;
    else return a.y < b.y;
}

double dist(const p &a, const p &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

p stations[100001];
p soldiers[100001];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &stations[i].x, &stations[i].y);
        }
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &soldiers[i].x, &soldiers[i].y);
        }
        sort(stations, stations + n, cmp);
        // sort(soldiers, soldiers + n, cmp);

        double res = sqrt(((double)1000000000) * ((double)1000000000)) + 1000;

        for (int i = 0; i < n; i++) {
            p lt = {soldiers[i].x - res, 0};
            auto lower = lower_bound(stations, stations + n, lt, cmp);
            p ut = {soldiers[i].x + res, 0};
            auto upper = upper_bound(stations, stations + n, ut, cmp);
            for (auto it = lower; it < upper; it++) {
                double distance = dist(soldiers[i], *it);
                if (distance < res) {
                    res = distance;
                }
            }
        }

        printf("%.3f\n", res);
    }

    return 0;
}