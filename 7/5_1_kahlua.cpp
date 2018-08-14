#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 1000000
using namespace std;
typedef long long LL;
int n, m, mod, prime[maxn+10], phi[maxn+10], mu[maxn+10], pre[maxn+10], inv[maxn+10];
bool check[maxn+10];
LL poww(LL a, LL b) {
    LL ret = 1;
    for (; b; (a*=a)%=mod, b>>=1) if (b&1) (ret*=a)%=mod;
    return ret;
}
void init() {
    int tot = 0; mu[1] = 1; phi[1] = 1;
    for (int i = 2; i <= maxn; ++i) {
        if (!check[i]) {
            prime[tot++] = i; mu[i] = -1; phi[i] = i-1;
        }
        for (int j = 0; j < tot; ++j) {
            if (i * prime[j] > maxn) break;
            check[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                mu[i*prime[j]] = 0;
                phi[i*prime[j]] = prime[j] * phi[i];
                break;
            }
            mu[i*prime[j]] = -mu[i];
            phi[i*prime[j]] = phi[i] * phi[prime[j]];
        }
    }
    for (int i = 1; i <= maxn; ++i) pre[i] = pre[i - 1] + mu[i];
}
LL calc(LL n, LL m) {
    LL sum=0, lim=min(n, m), ri;
    for (LL i = 1; i <= lim; i = ri+1) {
        ri = min(n/(n/i), m/(m/i));
        sum = (sum + (n/i) * (m/i) % mod * (pre[ri] - pre[i-1]) % mod) % mod;
    }
    return sum;
}
void work() {
    scanf("%d%d%d", &n, &m, &mod);
    inv[1] = 1;
    F2(i, 2, min(n, m)) inv[i] = 1ll * inv[mod%i] * (mod-mod/i) % mod;
    int lim = min(n, m), le, ri;
    LL ans = 0;
    F2(k, 1, lim) {
        ans = (ans + 1ll * k * inv[phi[k]] % mod * calc(n/k, m/k) % mod) % mod;
    }
    printf("%lld\n", ans);
}
int main() {
    init();
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}