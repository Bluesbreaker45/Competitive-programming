#include <queue>
#include <cstdio>
#include <cstring>

using std::queue;
int pre[2005];

void reverse(int k) {
    if(k != 1) {
        reverse(pre[k]);
        putchar(pre[k]>k?'O':'H');
    }
}

int main() {
    int n, m;
    while(scanf("%d %d", &n, &m) == 2 && (n || m)) {
        memset(pre, 0, sizeof(pre));
        queue<int> q;
        q.push(n);
        while(true) {
            int cur = q.front();
            q.pop();
            if(cur == m) {
                break;
            }
            if(cur * 3 <= 1000 && !pre[cur * 3]) {
                pre[cur * 3] = cur;
                q.push(cur * 3);
            }
            if(!pre[cur >> 1]) {
                pre[cur >> 1] = cur;
                q.push(cur >> 1);
            }
        }
        reverse(m);
        puts("");
    }
    return 0;
}
