#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
int n, m;
using namespace std;
typedef long long LL;
LL dp[1100], cnt[6];
const LL mod = 1e9+7;
void add(int u, int v) {
    dF2(state, (1<<n)-1, 0) {
        if (((state>>u)&1) && ((state>>v)&1)) {
            dp[state] = (dp[state] + dp[state-(1<<u)-(1<<v)]) % mod;
        }
    }
}
void del(int u, int v) {
    F(state, 0, (1<<n)) {
        if (((state>>u)&1) && ((state>>v)&1)) {
            dp[state] = (dp[state] - dp[state-(1<<u)-(1<<v)] + mod) % mod;
        }
    }
}
inline int dig(int x) { int ret = 0; while (x) ++ret, x &= x-1; return ret; }
void work() {
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    scanf("%d%d\n", &n, &m);
    F(i, 0, m) {
        char ch; int u, v;
        scanf("%c%d%d\n", &ch, &u, &v);
        --u, --v;
        if (ch == '+') add(u, v);
        else del(u, v);
        memset(cnt, 0, sizeof cnt);
        F(i, 0, (1<<n)) (cnt[dig(i)>>1] += dp[i]) %= mod;
        printf("%d", cnt[1]);
        F2(i, 2, (n>>1)) printf(" %d", cnt[i]); puts("");
    }
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}