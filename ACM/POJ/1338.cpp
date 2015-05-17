#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1501;

#define LL long long
LL a[MAXN];
int n, pre[3], num[3];

int main(){
    a[0] = 1LL;
    num[0] = 2; num[1] = 3; num[2] = 5;
    for (int i = 1; i < MAXN; ++i){
        LL ans = 0;
        for (int j = 0; j < 3; ++j)
            if (ans == 0 || ans > a[pre[j]] * (LL)num[j]){
                ans = a[pre[j]] * (LL)num[j];
            }
        a[i] = ans;
        for (int j = 0; j < 3; ++j)
            if (a[pre[j]] * (LL)num[j] == ans)
                ++pre[j];
    }

    while (~scanf("%d", &n) && n){
        printf("%lld\n", a[n-1]);
    }
    return 0;
}
