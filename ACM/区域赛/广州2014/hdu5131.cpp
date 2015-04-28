#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <map>
using namespace std;

const int MAXN = 310;
struct node{
	char name[MAXN];
	int val, id;
	bool operator<(const node&b)const{
		if (this->val != b.val) return this->val > b.val;
		return (strcmp(this->name, b.name) <= 0);
	}
}a[MAXN];

map<string, int> Hash;
int n, m, pos[MAXN], same[MAXN];
char name[MAXN][MAXN];

int main(){
	while (scanf("%d", &n) != EOF && n){
		Hash.clear();
		for (int i = 0; i < n; ++i){
			scanf("%s%d", a[i].name, &a[i].val);

			Hash[a[i].name] = i;
			a[i].id = i;
		}
		sort(a, a + n);
		for (int i = 0; i < n; ++i)
			printf("%s %d\n", a[i].name, a[i].val);

		memset(pos, -1, sizeof(pos));
		memset(same, 0, sizeof(same));
		for (int i = 0; i < n; ++i){
			pos[a[i].id] = i + 1;
			if (i && a[i].val == a[i-1].val)
				same[a[i].id] = same[a[i-1].id] + 1;
			else
				same[a[i].id] = 1;
		}

		scanf("%d", &m);
		for (int i = 0; i < m; ++i){
			char tmp[MAXN];
			scanf("%s", tmp);
			int id = Hash[tmp];

            if (same[id] == 1)
                printf("%d\n", pos[id]);
            else
                printf("%d %d\n", pos[id] - same[id] + 1, same[id]);
		}
	}
    return 0;
}
