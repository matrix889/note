#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100010;

int r[MAXN], e[MAXN], l[MAXN], id[MAXN], n, t;

bool cmp(int x, int y){
    return e[x] < e[y];
}

int main(){
    scanf("%d", &t);
    for (int k = 1; k <= t; ++k){
        scanf("%d", &n);
        for (int i = 0; i < n; ++i){
            scanf("%d%d%d", &r[i], &e[i], &l[i]);
            id[i] = i;
        }
        bool ok = true;
        sort(id, id+n, cmp);
        int work = 0;
        for (int i = 0; i < n; ++i){
            int u = id[i];
            if (e[u] - work < r[u]){
                ok = false;
                break;
            }
            work += r[u] + l[u];
        }
        printf("Case #%d: ", k);
        if (ok) puts("YES");
        else puts("NO");
    }
    return 0;
}

