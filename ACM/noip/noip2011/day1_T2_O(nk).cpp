#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;

const int MAXN = 200010;
const int N = 61;

int c[MAXN][N], partner[MAXN], n, k, p;
int color[MAXN], pay[MAXN];
LL ans;

int main(){
	scanf("%d%d%d", &n, &k, &p);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", &color[i], &pay[i]);
	memset(c, 0, sizeof(c));
	memset(partner, -1, sizeof(partner));

	for (int i = 1; i <= n; ++i){
		for (int j = 0; j < k; ++j)
			c[i][j] = c[i-1][j];
		++c[i][color[i]];

		if (pay[i] <= p)
			partner[i] = i;
		else
			partner[i] = partner[i-1];
	}

	ans = 0;
	for (int i = 1; i <= n; ++i){
		if (partner[i] == -1) continue;

		ans += c[partner[i]][color[i]];
		if (partner[i] == i)
			--ans;
	}
	printf("%lld\n", ans);
	return 0;
}
