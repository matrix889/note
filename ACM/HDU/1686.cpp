#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1100000;

char a[MAXN], b[MAXN];
int n, m, t, pre[MAXN], dp[MAXN];

int KMP(){
    n = strlen(a + 1); m = strlen(b + 1);
    memset(pre, 0, sizeof(pre));

    int j = 0, ans = 0;
    for (int i = 2; i <= n; ++i){
        while (j && a[i] != a[j+1]) j = pre[j];
        if (a[i] == a[j+1]) ++j;
        pre[i] = j;
    }

    j = 0;
    for (int i = 1; i <= m; ++i){
        while (j && b[i] != a[j+1]) j = pre[j];
        if (b[i] == a[j+1]) ++j;

        if (j == n){
            ++ans;
            j = pre[j];
        }
    }
    return ans;
}

int main(){
    scanf("%d", &t);
    while (t--){
        scanf("%s%s", a + 1, b + 1);
        printf("%d\n", KMP());
    }
    return 0;
}
