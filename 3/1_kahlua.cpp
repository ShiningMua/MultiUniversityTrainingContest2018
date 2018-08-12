#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 10000010
using namespace std;
typedef long long LL;
int mod, a[maxn], q[maxn], cnt[maxn], maxx[maxn], que[maxn];
namespace Input
{
    const int BUF = 65536;
    char buf[BUF + 1];
    char *head = buf, *tail = buf;
}
inline char inputchar()
{
    using namespace Input;
    if(head == tail)
        *(tail = (head = buf) + fread(buf, 1, BUF, stdin)) = 0;
    return *head++;
}
inline void inputnum(int &ret)
{
    char ch = inputchar();
    while(ch < '0' || ch > '9')
        ch = inputchar();
    ret = ch - '0';
    ch = inputchar();
    while(ch >= '0' && ch <= '9')
    {
        ret = ret * 10 + ch - '0';
        ch = inputchar();
    }
}
inline void inputsigned(int &ret)
{
    ret = 0;
    char ch = inputchar();
    while((ch < '0' || ch > '9') && ch != '-')
        ch = inputchar();
    bool neg = false;
    if(ch == '-')
        neg = true, ch = inputchar();
    while(ch >= '0' && ch <= '9')
    {
        ret = ret * 10 + ch - '0';
        ch = inputchar();
    }
    if(neg)
        ret = -ret;
}
LL add(LL a, LL b) { return (a+b) % mod; }
LL mul(LL a, LL b) { return a * b % mod; }
void work() {
    int n, m, k, p, q, rem;
    inputnum(n), inputnum(m), inputnum(k), inputnum(p), inputnum(q), inputnum(rem), inputnum(mod);
    F2(i, 1, k) inputnum(a[i]);
    F2(i, k+1, n) a[i] = add(mul(a[i-1], p), add(mul(q, i), rem));
    int f = 0, r = 0;
    que[0] = n+1;
    dF2(i, n, 1) {
        while (r > f && que[f]-i >= m) ++f;
        while (r > f && a[i] >= a[que[r-1]]) --r;
        que[r++] = i;
        maxx[i] = a[que[f]];
        cnt[i] = r-f;
    }
    LL A = 0, B = 0;
    F2(i, 1, n-m+1) A += i ^ maxx[i], B += i ^ cnt[i];
    printf("%lld %lld\n", A, B);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}