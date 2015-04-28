#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 15;

vector<int> g[MAXN];
int len[MAXN], n;
double ans;

double getArea(int a, int b, int c){
    double p = 1.0 * (a + b + c) / 2.0;
    return sqrt(p * (p-a) * (p-b) * (p-c));
}

void init(){
    for (int i = 0; i < MAXN; ++i)
        g[i].clear();
    ans = 0.0;
}

void solve(int x, int max_edge, double sum){
    if (x == n){
        ans = max(ans, sum);
        return;
    }
    double tmp_sum;
    int tmp_max_edge;
    //if (max_edge != -1 && max_edge <= len[x]) return;

    for (int i = 0; i <= n / 3; ++i){
        tmp_sum = sum;
        //tmp_max_edge = max_edge;
        if (i == 0){
            solve(x + 1, max_edge, sum);
            continue;
        }
        if (i > 1 && g[i-1].size() == 0) break;
        if (g[i].size() == 3) continue;

        if (g[i].size() == 2){
            if (g[i][0] + g[i][1] <= len[x])
                continue;
        }
        g[i].push_back(len[x]);
        if (g[i].size() == 3)
            tmp_sum += getArea(g[i][0], g[i][1], g[i][2]);
        if (g[i].size() == 2)
            tmp_max_edge = max(max_edge, g[i][0] + g[i][1]);

        solve(x + 1, tmp_max_edge, tmp_sum);
        g[i].pop_back();
    }
}

int main(){
    while (scanf("%d", &n) != EOF && n){
        for (int i = 0; i < n; ++i)
            scanf("%d", &len[i]);
        init();
        sort(len, len + n);

        solve(0, -1, 0.0);
        printf("%.2f\n", ans);
    }
    return 0;
}

