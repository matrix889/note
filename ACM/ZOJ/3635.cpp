#include <cstdio>
#include <cstring>
#include <algorithm>
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
using namespace std;

const int MAXN = 51000;

int sum[MAXN << 2], a[MAXN], n, M;

void PushUp(int rt){
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
void build(int l, int r, int rt){
    sum[rt] = 0;
    if (l == r) return;
    int m = (l + r) >> 1;
    build(lson); build(rson);
}

void update(int x, int l, int r, int rt){
    if (l == r){
        sum[rt] = 1;
        return;
    }
    int m = (l + r) >> 1;
    if (x <= m) update(x, lson);
    else update(x, rson);
    PushUp(rt);
}

int query(int L, int R, int l, int r, int rt){
    if (L <= l && r <= R) return sum[rt];
    int m = (l + r) >> 1, ans = 0;

    if (L <= m) ans += query(L, R, lson);
    if (m < R)  ans += query(L, R, rson);
    return ans;
}

int solve(int x){
    int l = 1, r = n;
    while (l < r){
        int m = (l + r) >> 1;
        int val = query(1, m, 1, n, 1);
        val = m - val;
        if (val < x) l = m + 1;
        else r = m;
    }
    return l;
}

int main(){
    while (scanf("%d", &n) != EOF){
        memset(a, 0, sizeof(a));
        int x;
        build(1, n, 1);
        for (int i = 0; i < n; ++i){
            scanf("%d", &x);
            a[i] = solve(x);
            update(a[i], 1, n, 1);
        }

        scanf("%d", &M);
        for (int i = 0; i < M; ++i){
            scanf("%d", &x);
            printf("%d", a[x-1]);
            if (i < M - 1) printf(" ");
            else puts("");
        }
    }
    return 0;
}

