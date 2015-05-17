#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define PII pair<int, int>

const int MAXN = 1000010;

int t, v[MAXN], a[MAXN], q[MAXN], cnt;
char s[1100], name[6];

void input(){
    sscanf(s, "%*s %*s %d", &v[cnt]);
    //printf("%d\n",  v[cnt]);
}

int l, r, popID;
void Init(){
    cnt = l = r = popID = 0;
}

void Pop_back(){
    --r;
}
void Pop_front(){
    ++l;
}
int Front_val(){
    if (l == r) return -1;
    return v[q[l]];
}
int Back_val(){
    if (l == r) return -1;
    return v[q[r-1]];
}
int Front(){
    if (l == r) return -1;
    return q[l];
}
int Back(){
    if (l == r) return -1;
    return q[r-1];
}
void Push_back(int id){
    q[r++] = id;
}

int main(){
    scanf("%d", &t);
    getchar();
    while (t--){
        Init();
        while (gets(s)){
            if (s[0] == 'E') break;
            if (s[0] == 'S') continue;
            if (s[0] == 'C'){
                input();
                while (l < r && Back_val() < v[cnt])
                    Pop_back();
                Push_back(cnt++);
            }
            else if (s[0] == 'Q'){
                printf("%d\n", Front_val());
            }
            else{
                while (l < r && Front() <= popID)
                    Pop_front();
                ++popID;
            }
        }
    }
    return 0;
}
