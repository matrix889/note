#include <cstdio>
#include <cstring>
#include <ctype.h>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 9;
const int MAXN = 510000;
const int d[4][2] = {{-1, 0},{1, 0},{0, -1},{0, 1}};
const char dchar[5] = "udlr";

struct state{
    int cantor, val;
    char a[N];

    bool operator<(const state&b)const{
        return this->val > b.val;
    }

    void init(){
        for (int i = 1; i < N; ++i)
            a[i - 1] = '0' + i;
        a[N-1] = '0';
    }
}start, goal;

struct path{
    int pre, dir;
}p[MAXN];

int mult[N], dist[MAXN];

void init_mult(){
    mult[1] = 1;
    for (int i = 2; i < N; ++i)
        mult[i] = mult[i-1] * i;
}
int cantor(char *s){
    int ret = 0, c;
    for (int i = 0; i < N-1; ++i){
        c = 0;
        for (int j = i + 1; j < N; ++j)
            if (s[j] < s[i]) ++c;
        ret += mult[8-i] * c;
    }
    return ret;
}

int guessDis(state s, state t){
    int ret = 0;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j)
            if (s.a[i] == t.a[j]){
                ret += abs(i/3 - j/3) + abs(i%3 - j%3);
                break;
            }
    }
    return ret;
}

priority_queue<state> q;
void init(){
    goal.init();
    goal.cantor = cantor(goal.a);
    memset(dist, -1, sizeof(dist));
    for (int i = 0; i < MAXN; ++i)
        p[i].pre = -1;
    while (!q.empty()) q.pop();
}

char s[100];
void getStart(){
    int cnt = 0;
    init();

    for (int i = 0; s[i]; ++i){
        if (isdigit(s[i]))
            start.a[cnt++] = s[i];
        else if (s[i] == 'x')
            start.a[cnt++] = '0';
    }

    start.cantor = cantor(start.a);
    dist[start.cantor] = 0;
    start.val = guessDis(start, goal);
    q.push(start);

    p[start.cantor].pre = -1;
}

inline int getPos(int x, int y){
    return x * 3 + y;
}
bool ok(int x, int y){
    return x >=0 && x < 3 && y >= 0 && y < 3;
}

int calc(state t){
    int ret = 0;
    for (int i = 0; i < N; ++i){
        if (t.a[i] == '0') continue;
        for (int j = i + 1; j < N; ++j)
            if (t.a[j] != '0' && t.a[i] > t.a[j]) ++ret;
    }
    return ret;
}

void solve(){
    getStart();
    if ((calc(start)%2) != (calc(goal)%2)){
        puts("unsolvable");
        return;
    }

    while (!q.empty()){
        state u = q.top(); q.pop();
        int pos;
        for (pos = 0; pos < N; ++pos)
            if (u.a[pos] == '0') break;

        for (int i = 0; i < 4; ++i){
            int dx = pos/3 + d[i][0], dy = pos%3 + d[i][1];
            if (!ok(dx, dy)) continue;

            state v = u;
            swap(v.a[pos], v.a[getPos(dx, dy)]);
            v.cantor = cantor(v.a);
            if (dist[v.cantor] != -1) continue;

            dist[v.cantor] = dist[u.cantor] + 1;
            v.val = dist[v.cantor] + guessDis(v, goal);
            q.push(v);

            //*****************
            p[v.cantor].pre = u.cantor;
            p[v.cantor].dir = i;
        }
    }
}

void print_path(int u){
    if (p[u].pre == -1) return;
    print_path(p[u].pre);
    printf("%c", dchar[p[u].dir]);
}

int main(){
    init_mult();
    int t = 0;
    while (gets(s)){
        solve();
        if (t) puts("");
        ++t;

        print_path(goal.cantor);
        puts("");
    }
    return 0;
}
