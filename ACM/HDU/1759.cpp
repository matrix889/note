#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <functional>
#define PII pair<int,int>
using namespace std;

const int MAXN = 1100;
const int INF = 0x3f3f3f3f;

int head[MAXN * 10], to[MAXN * 10], Next[MAXN * 10], cnt;
int reach[MAXN][MAXN];
char s[MAXN];

void init_edge(){
    memset(head, -1, sizeof(head));
    cnt = 0;
}
void add_edge(int u, int v){
    Next[cnt] = head[u]; to[cnt] = v; head[u] = cnt++;
}

int n, m, d[MAXN];

queue<PII > q;
void bfs(int s){
    memset(d, 0x3f, sizeof(d));
    d[s] = 0;
    q.push(make_pair(s, 0));

    while (!q.empty()){
        PII u = q.front();
        q.pop();

        for (int i = head[u.first]; i != -1; i = Next[i]){
            int v = to[i];
            if (d[v] != INF) continue;
            if (d[v] > d[u.first] + 1){
                d[v] = d[u.first] + 1;
                q.push(make_pair(v, d[v]));
            }
        }
    }
    for (int i = 0; i < n; ++i)
        if (d[i] != INF)
            reach[s][i] = 1;
}

int main(){
    while (~scanf("%d%d%s", &n, &m, s)){
        memset(reach, 0, sizeof(reach));
        for (int i = 0; i < n; ++i)
            reach[i][i] = 1;

        init_edge();
        while (m--){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            add_edge(u, v);
            reach[u][v] = 1;
        }
        for (int i = 0; i < n; ++i)
            bfs(i);

        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                ans += reach[i][j];
        printf("%d\n", ans);
    }
    return 0;
}
