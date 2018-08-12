#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 100010
using namespace std;
typedef long long LL;
int n;
char s[maxn];
struct node {
    int ri, le;
    bool operator < (const node& nd) const {
        bool flag1 = ri<=le, flag2 = nd.ri<=nd.le;
        if (flag1&&flag2) return ri < nd.ri;
        if (!flag1&&!flag2) return le > nd.le;
        if (flag1&&!flag2) return true;
        if (!flag1&&flag2) return false;
    }
}a[maxn];
int cnt = 0;
void proc(int idx, char* s) {
    int len = strlen(s), le = 0, ri = 0;
    F(i, 0, len) {
        if (s[i] == '(') ++le;
        else {
            if (le) --le, ++cnt;
            else ++ri;
        }
    }
    a[idx] = {ri, le};
}
void work() {
    cnt = 0;
    scanf("%d", &n);
    F(i, 0, n) {
        scanf("%s", s);
        proc(i, s);
    }
    sort(a, a+n);
//    F(i, 0, n) printf("%d %d\n", a[i].ri, a[i].le);
    int le = 0, ri = 0;
    F(i, 0, n) {
        cnt += min(le, a[i].ri);
        le -= min(le, a[i].ri);
        le += a[i].le;
    }
    printf("%d\n", cnt<<1);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}