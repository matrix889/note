#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;

const LL MAXN = 50010;
const LL M = 100000;

LL n, m;
int t;

LL calc(LL i, LL j){
    return i * i +  M * i + j * j - M * j + i * j;
}

LL solve2(LL v, LL j){
    LL l = 0, r = n + 1;
    while (r - l > 1){
        LL mid = (l + r) / 2;
        if (calc(mid, j) <= v) l = mid;
        else r = mid;
    }
    return l;
}
LL getNum(LL v){
    LL ans = 0;
    for (LL j = 1; j <= n; ++j)
        ans += solve2(v, j);
    return ans;
}
LL solve(){
    LL l = -M * n, r = n * n * 3 + 2 * n * M;
    while (r - l > 1){
        LL mid = (l + r) / 2;
        if (getNum(mid) < m) l = mid;
        else r = mid;
    }
    return r;
}

int main(){
    scanf("%d", &t);
    while (t--){
        scanf("%lld%lld", &n, &m);
        printf("%lld\n", solve());
    }
    return 0;
}

