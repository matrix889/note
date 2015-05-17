#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <functional>
using namespace std;

const int MAXN = 1510;
#define LL long long
#define mp(x,y) make_pair<LL,int>(x,y)

priority_queue<LL, vector<LL>, greater<LL> > q;
vector<LL> g;
map<LL, int> Hash;
int x, a[3];

int main(){
    a[0] = 2; a[1] = 3; a[2] = 5;
    q.push(1LL);
    while (!q.empty()){
        LL u = q.top();
        g.push_back(u);
        q.pop();
        if (g.size() == 1500) break;

        for (int i = 0; i < 3; ++i){
            LL v = u * a[i];
            if (Hash.find(v) != Hash.end())
                continue;
            q.push(u * a[i]);
            Hash.insert(mp(v, 1));
        }
    }

    while (scanf("%d", &x) != EOF && x){
        printf("%lld\n", g[x-1]);
    }
    return 0;
}
