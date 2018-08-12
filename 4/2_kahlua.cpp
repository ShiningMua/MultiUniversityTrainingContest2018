#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 100010
using namespace std;
typedef long long LL;
const LL mod=1e9+7;
int blo, bl[maxn+10];
LL poww(LL a, LL b) {
    LL ret = 1;
    for (; b; (a*=a)%=mod, b>>=1) if (b&1) (ret*=a)%=mod;
    return ret;
}
LL f[maxn+10], g[maxn+10];
void init() {
    f[0] = 1ll;
    F2(i, 1, maxn) f[i] = f[i-1] * i % mod;
    F2(i, 0, maxn) g[i] = poww(f[i], mod-2);
    blo = sqrt(maxn);
    F2(i, 0, maxn) bl[i] = i / blo;
}
LL nCr(int n, int r) {
    return f[n] * g[r] % mod * g[n-r] % mod;
}
struct node {
    int n, m, id;
    bool operator < (const node& nd) const {
        return bl[n] == bl[nd.n] ? m < nd.m : bl[n] < bl[nd.n];
    }
}q[maxn+10];
LL ret[maxn+10];
void add(LL& a, LL b) { a = (a+b)%mod; }
void sub(LL& a, LL b) { a = (a+mod-b)%mod; }
void mul(LL& a, LL b) { a = a*b%mod; }
int main() {
    init();
    int T;
    scanf("%d", &T);
    F(i, 0, T) {
        scanf("%d%d", &q[i].n, &q[i].m);
        q[i].id = i;
    }
    sort(q, q+T);
    int n = 1, m = 0;
    LL ans = 1ll;
    F(i, 0, T) {
        while (q[i].n > n) add(ans, ans), sub(ans, nCr(n++, m));
        while (q[i].n < n) add(ans, nCr(--n, m)), mul(ans, g[2]);
        while (q[i].m > m) add(ans, nCr(n, ++m));
        while (q[i].m < m) sub(ans, nCr(n, m--));
        ret[q[i].id] = ans;
    }
    F(i, 0, T) printf("%lld\n", ret[i]);
    return 0;
}