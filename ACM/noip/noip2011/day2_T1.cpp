#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL long long
const int MOD = 10007;

int p[1010][1010], a, b, k, n, m;

int getMod(LL x){
    return x % MOD;
}

int main(){
    scanf("%d%d%d%d%d", &a, &b, &k, &n, &m);
    memset(p, 0, sizeof(p));
    for (int i = 0; i <= k; ++i)
        p[i][0] = 1;
    for (int i = 1; i <= k; ++i)
        for (int j = 1; j <= i; ++j)
            p[i][j] = getMod((LL)p[i-1][j]+ p[i-1][j-1]);

    int ans = p[k][n];
    for (int i = 0; i < n; ++i)
        ans = getMod((LL)ans * a);
    for (int j = 0; j < m; ++j)
        ans = getMod((LL)ans * b);
    printf("%d\n", ans);
    return 0;
}
