#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 100010
int pre[maxn], ans[maxn];
using namespace std;
typedef long long LL;
void work() {
    int n, m;
    scanf("%d%d", &n, &m);
    set<int> st;
    F2(i, 1, n) st.insert(i), pre[i] = i;
    st.erase(1);
    F(i, 0, m) {
        int l, r;
        scanf("%d%d", &l, &r);
        pre[r] = min(pre[r], l);
    }
    dF2(i, n-1, 1) pre[i] = min(pre[i], pre[i+1]);
    int l = 1; ans[1] = 1;
    F2(i, 2, n) {
        while (l < pre[i]) {
            st.insert(ans[l++]);
        }
        ans[i] = *st.begin();
        st.erase(ans[i]);
    }
    printf("%d", ans[1]);
    F2(i, 2, n) printf(" %d", ans[i]); puts("");
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}