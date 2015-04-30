#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x0f0f0f0f;
const int MAXN = 51;

int dist[MAXN][MAXN], g[MAXN][MAXN], vis[MAXN], n, m, ans;

void update(int &x, int y){
    x = min(x, y);
}

void solve(int id){
    memset(dist, 0x0f, sizeof(dist));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            if (i == id || j == id) continue;
            dist[i][j] = g[i][j];
        }

    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                update(dist[i][j], dist[i][k] + dist[k][j]);

    ans = max(ans, dist[1][n]);
}

int main(){
    while (scanf("%d%d", &n, &m) && n + m){
        memset(g, 0x0f, sizeof(g));
        for (int i = 0; i < m; ++i){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            update(g[u][v], w);
            update(g[v][u], w);
        }

        ans = 0;
        for (int i = 2; i < n; ++i)
            solve(i);

        if (ans == INF) puts("Inf");
        else printf("%d\n", ans);
    }
    return 0;
}
