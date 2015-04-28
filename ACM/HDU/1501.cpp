#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 510;

char a[MAXN], b[MAXN], c[MAXN];
int n, m, t;
bool dp[MAXN][MAXN];

int main(){
    scanf("%d", &t);
    for (int k = 1; k <= t; ++k){
        memset(dp, 0, sizeof(dp));
        dp[0][0] = true;

        scanf("%s%s%s", a + 1, b + 1, c + 1);
        n = strlen(a + 1); m = strlen(b + 1);
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= m; ++j){
                if (i && a[i] == c[i+j] && dp[i-1][j])
                    dp[i][j] = true;
                if (j && b[j] == c[i+j] && dp[i][j-1])
                    dp[i][j] = true;
            }
        if (n + m == (int)strlen(c+1) && dp[n][m])
            printf("Data set %d: yes\n", k);
        else
            printf("Data set %d: no\n", k);
    }
    return 0;
}
