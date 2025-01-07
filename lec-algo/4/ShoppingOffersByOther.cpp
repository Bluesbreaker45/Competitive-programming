#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define mst(a, b) memset((a), (b), sizeof(a))
#define inf 0x3f3f3f3f
#define maxn 100
#define Abs(a) ((a) > 0 ? (a) : -(a))
int val[6];
int qulility[6];
struct obje
{
    int w[5];
    int value;
} obj[100];
int dp[6][6][6][6][6];
int main()
{
    int n, t, x;
    int c, qu, value;
    while (cin >> n)
    {
        mst(dp, inf);
        mst(obj, 0);
        mst(qulility, 0);
        mst(val, 0);
        map<int, int> ob;
        int i, j;
        for (i = 0; i < n; i++)
        {
            cin >> c >> qu >> value;
            ob[c] = i;
            val[i] = value;
            qulility[i] = qu;
            obj[i].w[i] = 1;
            obj[i].value = value;
        }
        cin >> t;
        for (j = i; j < t + i; j++)
        {
            cin >> x;
            int a, b;
            for (int k = 0; k < x; k++)
            {
                cin >> a >> b;
                obj[j].w[ob[a]] = b;
            }
            cin >> x;
            obj[j].value = x;
        }
        dp[0][0][0][0][0] = 0;
        for (int i = 0; i < j; i++)
            for (int k = 0; k <= qulility[0]; k++)
                for (int l = 0; l <= qulility[1]; l++)
                    for (int m = 0; m <= qulility[2]; m++)
                        for (int n = 0; n <= qulility[3]; n++)
                            for (int o = 0; o <= qulility[4]; o++)
                            {
                                if (k >= obj[i].w[0] && l >= obj[i].w[1] && m >= obj[i].w[2] && n >= obj[i].w[3] && o >= obj[i].w[4])
                                    dp[k][l][m][n][o] = min(dp[k][l][m][n][o], dp[k - obj[i].w[0]][l - obj[i].w[1]][m - obj[i].w[2]][n - obj[i].w[3]][o - obj[i].w[4]] + obj[i].value);
                            }
        cout << dp[qulility[0]][qulility[1]][qulility[2]][qulility[3]][qulility[4]];
    }
    return 0;
}
