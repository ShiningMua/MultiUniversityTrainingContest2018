#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 1000000
using namespace std;
typedef long long LL;
int n, m, mod, f[maxn+10], g[maxn+10], inv[maxn+10], prime[maxn], phi[maxn+10];
bool check[maxn+10];
void init() {
    int tot = 0; phi[1] = 1;
    for (int i = 2; i <= maxn; ++i) {
        if (!check[i]) {
            prime[tot++] = i; phi[i] = i-1;
        }
        for (int j = 0; j < tot; ++j) {
            if (i * prime[j] > maxn) break;
            check[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                phi[i*prime[j]] = prime[j] * phi[i];
                break;
            }
            phi[i*prime[j]] = phi[i] * phi[prime[j]];
        }
    }
}
void work() {
    scanf("%d%d%d", &n, &m, &mod);
    inv[1] = 1;
    F2(i, 2, min(n, m)) inv[i] = 1ll * inv[mod%i] * (mod-mod/i) % mod;

    F2(i, 1, min(n, m)) f[i] = 1ll * (n/i) * (m/i) % mod;
    LL ans=0;
    dF2(i, min(n, m), 1) {
        g[i] = f[i];
        for (int j = i+i; j <= min(n, m); j+=i) g[i] = (g[i]-g[j]+mod) % mod;
        ans = (ans + 1ll * i * inv[phi[i]] % mod * g[i] % mod) % mod;
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
[ Copy to Clipboard ]    [ Save to File]

