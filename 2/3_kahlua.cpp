#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 100010
#define maxm 500010
using namespace std;
typedef long long LL;
struct Edge {
    int to, ne;
}edge[maxm];
int ne[maxn], fa[maxn], tot, top, stk[maxm], deg[maxn], n, m, split[maxm];
void add(int u, int v) {
    edge[tot] = {v, ne[u]};
    ne[u] = tot++;
}
inline int find(int u) { return u==fa[u]?u:fa[u]=find(fa[u]); }
bool vis[maxn<<2];
void dfs(int u) {
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        if (vis[i>>1]) continue;
        vis[i>>1] = true;
        dfs(edge[i].to);
        stk[top++] = (i&1) ? -(i>>1)-1 : (i>>1)+1;
    }
}
vector<int> ans[maxn<<1];
vector<int> odd[maxn];
void init() {
    tot = 0;
    memset(ne, -1, sizeof ne);
    memset(vis, 0, sizeof vis);
    memset(deg, 0, sizeof deg);
    F2(i, 1, n) fa[i] = i;
}
void pos() {
    F2(i, 1, n) if (fa[i]==i) odd[i].clear();
}
void stkoutput() {
    F(i, 0, top) printf("%d ", stk[i]); puts("");
}
void work() {
    init();
    F(i, 0, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v); add(v, u);
        ++deg[u], ++deg[v];
        fa[find(u)] = find(v);
    }
    F2(i, 1, n) {
        if (deg[i] & 1) odd[find(i)].push_back(i);
    }
    int w = 0;
    F2(i, 1, n) {
        if (find(i) != i) continue;
        if (odd[i].size() > 0) {
            int sz = odd[i].size();
            for (int j = 0; j < sz; j+=2) {
                add(odd[i][j], odd[i][j+1]),
                add(odd[i][j+1], odd[i][j]);
            }
            top = 0;
            dfs(i);
            int cnt = 0;
            F(j, 0, top) if (abs(stk[j]) > m) split[cnt++] = j;
            F(j, 0, cnt-1) {
                ans[++w].clear();
                dF(k, split[j+1]-1, split[j]) ans[w].push_back(stk[k]);
            }
            ans[++w].clear();
            dF2(k, split[0]-1, 0) ans[w].push_back(stk[k]);
            dF(k, top-1, split[cnt-1]) ans[w].push_back(stk[k]);
        }
        else {
            top = 0;
            dfs(i);
            ans[++w].clear();
            while (top) ans[w].push_back(stk[--top]);
        }
    }
    int num = w;
    F2(i, 1, w) if (!ans[i].size()) --num;
    printf("%d\n", num);
    F2(i, 1, w) if (ans[i].size()) {
        int sz = ans[i].size();
        printf("%d", sz);
        F(j, 0, sz) printf(" %d", ans[i][j]); puts("");
    }
    pos();
}
int main() {
    while (scanf("%d%d", &n, &m) != EOF) work();
    return 0;
}