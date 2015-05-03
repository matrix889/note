#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 210;
const int N = 61;
const int Debug = 1;

int dp[N][MAXN], work[N][MAXN], a[N], b[N], n, x, y;
int t;

void update(int &X, int Y){
    X = max(X, Y);
}
int calc(int work_time){
    memset(dp, -1, sizeof(dp));
    memset(work, -1, sizeof(work));

    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= min(x, work_time/a[i]); ++j)
            work[i][j] = (work_time-a[i]*j) / b[i];

    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= x; ++j)
            for (int k = 0; k <= j; ++k){
                if (dp[i-1][j-k] == -1) continue;
                if (work[i][k] == -1) continue;
                update(dp[i][j], dp[i-1][j-k] + work[i][k]);
            }

    if (Debug && work_time == 2){
        for (int i = 1; i <= n; ++i){
            for (int j = 0; j <= x; ++j)
                printf("%d ", dp[i][j]);
            puts("");
        }
    }
    return dp[n][x];
}

int solve(){
    int l = 1, r = MAXN * 2000;
    while (r-l > 1){
        int m = (l + r) >> 1;
        if (calc(m) >= y) r = m;
        else l = m;
    }
    return r;
}

int main(){
    scanf("%d", &t);
    for (int l = 1; l <= t; ++l){
        scanf("%d%d%d", &n, &x, &y);
        for (int i = 1; i <= n; ++i)
            scanf("%d%d", &a[i], &b[i]);

        printf("Case %d: %d\n", l, solve());
    }
    return 0;
}
