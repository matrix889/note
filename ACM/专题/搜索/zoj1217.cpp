#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctype.h>
#include <algorithm>
using namespace std;

const int N = 9;
const int sz = 3;
const int INF = 1e9;
const int d[4][2] = {{1,0}, {0,1}, {0,-1},{-1,0}};
const char dchar[5] = "drlu";

char goal[11] = "1234567890";

char start[11];

int guessDist(){
    int ret = 0;

    for (int i = 0; i < N; ++i){
        if (start[i] == '0') continue;

        for (int j = 0; j < N; ++j)
            if (start[i] == goal[j]){
                ret += abs(i/sz - j/sz) + abs(i%sz -j%sz);
                break;
            }
    }
    return ret;
}

bool ok(int x, int y){
    return x >= 0 && x < sz && y >= 0 && y < sz;
}

bool solved;

inline int getPos(int x, int y){
    return x*3 + y;
}

int path[1100];

void init(){
    memset(path, -1, sizeof(path));
}

int dfs(int depth, int pos, int dir, int bound){
    int h = guessDist();
    if (h + depth > bound) return h + depth;
    if (h == 0){
        solved = true;
        return depth;
    }

    int newBound = INF;
    for (int i = 0; i < 4; ++i){
        if (i + dir == 3) continue;
        int dx = pos/sz + d[i][0], dy = pos%sz + d[i][1];
        if (!ok(dx, dy)) continue;

        path[depth] = i;
        swap(start[pos], start[getPos(dx, dy)]);
        int t = dfs(depth+1, getPos(dx, dy), i, bound);
        if (solved) return t;
        newBound = min(newBound, t);
        swap(start[pos], start[getPos(dx, dy)]);
        path[depth] = -1;
    }
    return newBound;
}

bool calc(char *s){
    int ret = 0;
    for (int i = 0; i < N; ++i){
        if (s[i] == '0') continue;

        for (int j = i + 1; j < N; ++j)
            if (s[j] != '0' && s[j] < s[i])
                ++ret;
    }
    return ret % 2 == 1;
}

int IDAstat(){
    int pos = 0, bound = guessDist();
    solved = false;

    while (start[pos] != '0' && pos < N) ++pos;

    while (!solved && bound < 100){
        bound = dfs(0, pos, -100, bound);
    }
    return bound;
}

void solve(){
    if (calc(start) != calc(goal))
        puts("unsolvable");
    else{
        init();
        IDAstat();
        for (int i = 0; path[i] != -1; ++i)
            putchar(dchar[path[i]]);
        puts("");
    }
}

char s[100];

void input(){
    int cnt = 0;
    for (int i = 0; s[i]; ++i)
        if (isdigit(s[i])) start[cnt++] = s[i];
        else if (s[i] == 'x') start[cnt++] = '0';
}

int main(){
    while (gets(s)){
        input();
        solve();
    }
    return 0;
}
