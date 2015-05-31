#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
const double INF = 1e100;

double e[MAXN], dp[MAXN], p;
int n, t, x;

int main(){
    scanf("%d", &t);
    for (int k = 1; k <= t; ++k){
        scanf("%d%lf%d", &n, &p, &x);
        e[0] = 0.0;
        for (int i = 1; i <= n; ++i)
            e[i] = (e[i-1] + 1) / (1-p);

        for (int i = 1; i <= n; ++i){
            dp[i] = INF;
            for (int j = i-1; j >= 0; --j){
                if (e[i-j] > dp[i]) break;
                dp[i] = min(dp[i], dp[j] + e[i-j] + x);
            }
        }
        printf("Case #%d: %.6f\n", k, dp[n]);
    }
    return 0;
}
