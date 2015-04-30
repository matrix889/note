#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 110;
const int INF = 0x0f0f0f0f;

int g[MAXN][MAXN], dist[MAXN][MAXN], n, m;

inline void update(int &x, int v){
    x = min(x, v);
}

int main(){
    while (scanf("%d%d", &n, &m) != EOF){
        memset(dist, 0x0f, sizeof(dist));
        memset(g, 0x0f, sizeof(g));

        for (int i = 0; i < m; ++i){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            --u; --v;
            update(g[u][v], w);
            update(g[v][u], w);
        }

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dist[i][j] = g[i][j];

        int ans = INF;
        for (int k = 0; k < n; ++k){
            for (int i = 0; i < k; ++i)
                for (int j = i + 1; j < k; ++j)
                    update(ans, dist[i][j] + g[i][k] + g[k][j]);

            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    update(dist[i][j], dist[i][k] + dist[k][j]);
        }
        if (ans == INF)
            puts("It's impossible.");
        else
            printf("%d\n", ans);
    }
    return 0;
}
