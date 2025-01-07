#include <iostream>
#include <vector>
using namespace std;

struct ExPoint {
    int a;
    int b;
    double rate[2];
    double comm[2];
};

ExPoint exPoints[101];
vector<ExPoint> relatedEdges[101];

int N;
int M;
int S;
double V;
double dist[103];

double exchange(int destCurrency, ExPoint exPoint) {
    int edge = destCurrency == exPoint.b ? 0 : 1;
    int source = destCurrency == exPoint.b ? exPoint.a : exPoint.b;
    double sourceValue = dist[source];
    double exchanged = (sourceValue - exPoint.comm[edge]) * exPoint.rate[edge];
    return exchanged;
}

bool bellman() {
    dist[S] = V;

    bool notConverge = true;
    for (int i = 1; i < N; i++) {
        bool changed = false;
        for (int i = 0; i <= N; i++) {
            for (auto exPoint : relatedEdges[i]) {
                double exchanged = exchange(i, exPoint);
                if (dist[i] < exchanged) {
                    dist[i] = exchanged;
                    changed = true;
                }
            }
        }

        if (!changed) {
            notConverge = false;
            break;
        }
    }

    if (notConverge) {
        for (int i = 0; i <= N; i++) {
            for (auto exPoint : relatedEdges[i]) {
                double exchanged = exchange(i, exPoint);
                if (dist[i] < exchanged) {
                    return true;
                }
            }

        }
    }

    return false;
}

int main() {
    while (cin >> N) {
        for (int i = 0; i < 103; i++) {
            dist[i] = 0;
        }
        for (int i = 0; i < 101; i++) {
            relatedEdges[i].clear();
        }

        cin >> M >> S >> V;
        for (int i = 0; i < M; i++) {
            cin >> exPoints[i].a >> exPoints[i].b;
            cin >> exPoints[i].rate[0] >> exPoints[i].comm[0] >> exPoints[i].rate[1] >> exPoints[i].comm[1];
            relatedEdges[exPoints[i].a].push_back(exPoints[i]);
            relatedEdges[exPoints[i].b].push_back(exPoints[i]);
        }

        if (bellman()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}