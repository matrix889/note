#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = 13;

double dp[1 << MAXN];
int len[MAXN], n;
vector<int> g;

double getArea(int a, int b, int c){
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p-a) * (p-b) * (p-c));
}

void update(double &x, double y){
    x = max(x, y);
}
int main(){
    while (scanf("%d", &n) != EOF && n){
        for (int i = 0; i < n; ++i)
            scanf("%d", &len[i]);
        memset(dp, 0, sizeof(dp));
        sort(len, len + n);

        for (int i = 0; i < n - 2; ++i)
            for (int j = i + 1; j < n - 1; ++j)
                for (int k = j + 1; k < n; ++k){
                    if (len[i] + len[j] <= len[k]) continue;
                    int st = (1 << i) + (1 << j) + (1 << k);
                    update(dp[st], getArea(len[i], len[j], len[k]));
                    g.push_back(st);
                }

        for (int i = 0; i < (1 << n); ++i)
            for (int j = 0; j < (int)g.size(); ++j){
                if (i & g[j]) continue;
                update(dp[i | g[j]], dp[i] + dp[g[j]]);
            }
        double sum = 0.0;
        for (int i = 0; i < (1 << n); ++i)
            sum = max(sum, dp[i]);
        printf("%.2f\n", sum);
    }
    return 0;
}

