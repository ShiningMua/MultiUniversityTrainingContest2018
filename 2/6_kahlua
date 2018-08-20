#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 3000
typedef long long LL;
const int mod = 998244353;
using namespace std;
int C[maxn+10][maxn+10], bi[(maxn+10)*(maxn+10)], coeff1[maxn+10], coeff2[maxn+10];
int n, m, a, b;
inline int norm1(LL x) { return x >= mod ? x-mod : x; }
inline int norm2(LL x) { return x < 0 ? x+mod : x; }
void init() {
  C[1][0] = C[1][1] = 1;
  F2(i, 2, maxn) {
    C[i][0] = C[i][i] = 1;
    F(j, 1, i) {
      C[i][j] = norm1((LL)C[i-1][j] + C[i-1][j-1]);
    }
  }
  bi[0] = 1; int lim = maxn*maxn;
  F2(i, 1, lim) bi[i] = norm1((1ll * bi[i-1]) << 1);
}
void work() {
  F2(i, a, n) {
    coeff1[i] = 1;
    F(u, a, i) {
      coeff1[i] = norm2(coeff1[i] - 1ll * C[i][u] * coeff1[u] % mod);
    }
  }
  F2(i, b, m) {
    coeff2[i] = 1;
    F(u, b, i) {
      coeff2[i] = norm2(coeff2[i] - 1ll * C[i][u] * coeff2[u] % mod);
    }
  }
  int ans = 0;
  F2(i, a, n) {
    int temp = 1ll * C[n][i] * coeff1[i] % mod;
    F2(j, b, m) {
      ans = norm1(ans + 1ll * temp * C[m][j] % mod * coeff2[j] % mod * bi[(n-i)*(m-j)] % mod);
    }
  }
  printf("%d\n", ans);
}
int main() {
  init();
  while (scanf("%d%d%d%d", &n, &m, &a, &b) != EOF) work();
  return 0;
}
