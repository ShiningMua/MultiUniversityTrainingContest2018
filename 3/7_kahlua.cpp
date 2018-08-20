#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define PI pair<int, int>
#define mp make_pair
#define maxn 200010
typedef long long ll;
using namespace std;
struct point {
    ll x, y; int idx;
    point() {}
    point(ll x, ll y, int i) : x(x), y(y), idx(i) {}
    bool operator < (const point& pt) { return x == pt.x ? y < pt.y : x < pt.x; }
}v[maxn], q[maxn];
int ret[maxn], minn[maxn];
inline ll cross(point p1, point p2, point p3) {
    return (p2.x-p1.x) * (p3.y-p1.y) - (p2.y-p1.y) * (p3.x-p1.x);
}
void work() {
    int n;
    scanf("%d", &n);
    int tot = 0;
    map<PI, int> hs;
    F(i, 0, n) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (hs.count(mp(x,y))) continue;
        hs[mp(x,y)] = i, v[tot++] = point(x, y, i);
    }
    sort(v, v+tot);
    int num = 0;
    F(i, 0, tot) {
        while (num>1 && cross(q[num-2], q[num-1], v[i]) > 0) --num;
        q[num++] = v[i];
    }
    // F(i, 0, num) printf("%d ", q[i].idx); puts("");
    vector<int> dup;
    int cnt = 0;
    ret[cnt++] = 0;
    for (int i = 0; i < num; ) {
        // printf("i = %d\n", i);
        int j = i+1;
        while (j < num-1 && cnt >= 1 && cross(q[i], q[j], q[j+1]) == 0) ++j;
        minn[j] = q[j].idx;
        // printf("%d\n", j);
        dF2(k, j-1, i) {
            minn[k] = min(minn[k+1], q[k].idx);
        }
        F2(k, i+1, j) {
            if (q[k].idx == minn[k]) ret[cnt++] = q[k].idx;
        }
        i = j;
        // F(k, 0, cnt) printf("%d%c", ret[k], " \n"[k==cnt-1]);
    }
    F(i, 0, cnt-1) printf("%d%c", ret[i]+1, " \n"[i==cnt-2]);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) work();
  return 0;
}
