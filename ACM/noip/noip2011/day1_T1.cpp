#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10010;

bool cover(int x1, int y1, int x2, int y2, int a, int b){
    return a >= x1 && a <= x2 && b >= y1 && b <= y2;
}

int n, x[MAXN][2], y[MAXN][2];

int main(){
    scanf("%d", &n);
    int id = -1;
    for (int i = 1; i <= n; ++i){
         scanf("%d%d%d%d", &x[i][0], &y[i][0], &x[i][1], &y[i][1]);
         x[i][1] = x[i][0] + x[i][1] - 1;
         y[i][1] = y[i][0] + y[i][1] - 1;
    }
    int a, b;
    scanf("%d%d", &a, &b);
    for (int i = 1; i <= n; ++i){
         if (cover(x[i][0], y[i][0], x[i][1], y[i][1], a, b))
             id = i;
    }
    printf("%d\n", id);
    return 0;
}
