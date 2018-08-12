#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 100010
using namespace std;
typedef long long LL;
struct Edge { int to, ne; }edge[maxn];
int sz[maxn], fa[maxn], to[maxn], deg[maxn], tot, ne[maxn];
char c[maxn], s[10];
bool vis[maxn];
inline int find(int u) { return fa[u] == u ? u : fa[u] = find(fa[u]); }
inline void unionn(int a, int b) { fa[find(a)] = find(b); }
void add(int u, int v) {
  edge[tot] = {v, ne[u]};
  ne[u] = tot++;
}
void dfs(int u) {
  sz[u] = 1;
  for (int i = ne[u]; ~i; i = edge[i].ne) {
    dfs(edge[i].to);
    sz[u] += sz[edge[i].to];
  }
}
int solve(int u) {
  if (find(to[u]) != find(u)) return 0;
  dfs(to[u]);
  return sz[to[u]];
}
void work() {
  memset(deg, 0, sizeof deg);
  tot = 0;
  memset(ne, -1, sizeof ne);
  memset(vis, 0, sizeof vis);
  int n, u;
    scanf("%d", &n);
  F2(i, 1, n) fa[i] = i;
    F2(i, 1, n) {
        scanf("%d%s", &u, s);
        to[i] = u;
        if ((c[i]=s[0])=='w') continue;
        ++deg[i];
        add(u, i);
        unionn(u, i);
    }
  int ans = 0;
    F2(i, 1, n) {
        if (!vis[find(i)] && !deg[i]) {
            vis[fa[i]] = true;
            ans += solve(i);
        }
    }
  printf("0 %d\n", ans);
}
int main() {
  int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}