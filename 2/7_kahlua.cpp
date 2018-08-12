#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 100010
using namespace std;
typedef long long LL;
bool exist[510];
int x, n, m, a[maxn];
LL c[maxn];
char s[10];
struct node {
  int l, r, tag, val;
}tr[maxn<<2];
void output() {
    puts("output:");
    F2(i,1,9) printf("%d %d %d\n", i, tr[i].val, tr[i].tag);
    puts("");
}
inline int midi(int l, int r) { return l+r>>1; }
inline void pushup(int rt) {
  tr[rt].val = min(tr[rt<<1].val, tr[rt<<1|1].val);
}
inline int lowbit(int x) { return x & (-x); }
inline void add(int x, int y) { while (x <= n) c[x] += y, x += lowbit(x); }
inline LL query(int x) { LL ret = 0; while (x) ret += c[x], x -= lowbit(x); return ret; }
void build(int rt, int l, int r) {
    tr[rt].l = l, tr[rt].r = r;
  if (l==r) {
    tr[rt].val = a[l];
    return;
  }
  int mid = midi(l, r);
  build(rt<<1, l, mid);
  build(rt<<1|1, mid+1, r);
  pushup(rt);
}
inline void pushdown(int rt) {
  if (tr[rt].tag) {
  tr[rt<<1].val -= tr[rt].tag;
  tr[rt<<1|1].val -= tr[rt].tag;
  tr[rt<<1].tag += tr[rt].tag;
  tr[rt<<1|1].tag += tr[rt].tag;
  tr[rt].tag = 0;
  }
}
void arrayoutput() {
    F2(i ,1, n) printf("%d ", c[i]); puts("");
}
void modify(int rt, int l, int r) {
//    printf("%d %d %d\n", rt, l, r);
  if (tr[rt].l==l && tr[rt].r==r) {
    if (l == r) {
        --tr[rt].val;
//        printf("val = %d\n", tr[rt].val);
        if (tr[rt].val <= 0) {
          add(l, 1);
          tr[rt].val += a[l];
//          puts("hello");
//          arrayoutput();
        }
        return;
    }
    if (tr[rt].val > 1) {
        --tr[rt].val;
        ++tr[rt].tag;
        return;
    }
  }
  pushdown(rt);
  int mid = midi(tr[rt].l, tr[rt].r);
//  printf("%d\n", mid);
  if (r <= mid) modify(rt<<1, l, r);
  else if (l > mid) modify(rt<<1|1, l, r);
  else {
    modify(rt<<1, l, mid);
    modify(rt<<1|1, mid+1, r);
  }
  pushup(rt);
}
void work() {
    memset(c, 0, sizeof c);
    memset(tr, 0, sizeof tr);
  F2(i, 1, n) scanf("%d", &a[i]);
  build(1, 1, n);
//  output();
  while (m--) {
    int l, r;
    scanf("%s%d%d", &s, &l, &r);
    if (s[0] == 'a') {
      modify(1, l, r);
//        output();
    }
    else printf("%lld\n", query(r)-query(l-1));
  }
}
int main() {
  while (scanf("%d%d", &n, &m) != EOF) work();
  return 0;
}