#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 110000;

struct node{
    int calc;
    node *son[26];
    node(){
        calc = 0;
        for (int i = 0; i < 26; ++i)
            son[i] = NULL;
    }
}*root;

char s[11];

void Insert(char *a){
    node *u = root;
    for (int i = 0; a[i]; ++i){
        int v = a[i] - 'a';

        if (u->son[v] == NULL) u->son[v] = new node();
        u = u->son[v];
        ++u->calc;
    }
}

int Find(char *a){
    node *u = root;
    for (int i = 0; a[i]; ++i){
        int v = a[i] - 'a';

        if (u->son[v] == NULL) return 0;
        u = u->son[v];
    }
    return u->calc;
}

int main(){
    root = new node();

    while (gets(s) && strlen(s) != 0){
        Insert(s);
    }
    while (gets(s))
        printf("%d\n", Find(s));
    return 0;
}
