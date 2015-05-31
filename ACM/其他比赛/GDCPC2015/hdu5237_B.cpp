#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000010;
const int BITS = 8;
const int BIT = 6;
const char ans[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";

char s[MAXN];
int n, k, t, c, cnt, ret[MAXN], ret2[MAXN];
int next_cnt, id;

void sub(){
    --id;
    if (id == -1){
        ret2[next_cnt++] = c;
        c = 0;
        id = 5;
    }
}
void convert(){
    for (int i = 0; i < cnt; ++i)
        ret[i] = (int)ans[ret[i]];
}
int main(){
    scanf("%d", &t);
    for (int l = 1; l <= t; ++l){
        scanf("%d%s", &k, s);
        cnt = strlen(s);
        for (int i = 0; i < cnt; ++i)
            ret[i] = (int)s[i];
        while (k--){
            next_cnt = c = 0;
            id = 5;
            for (int i = 0; i < cnt; ++i){
                for (int j = BITS - 1; j >= 0; --j){
                    if ((ret[i] & (1 << j)) == 0){
                        sub();
                        continue;
                    }
                    c = c + (1 << id);
                    sub();
                }
            }
            if (id != 5) ret2[next_cnt++] = c;

            cnt = next_cnt;
            for (int i = 0; i < cnt; ++i)
                ret[i] = ret2[i];

            while (cnt % 4) ret[cnt++] = 64;
            convert();
        }

        printf("Case #%d: ", l);
        for (int i = 0; i < cnt; ++i)
            printf("%c", (char)ret[i]);
        puts("");
    }
    return 0;
}
