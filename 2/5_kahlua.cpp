#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define sz 47
#define maxn sz*sz
int a[maxn+10][maxn+10];
using namespace std;
typedef long long LL;
int main() {
//    freopen("in.txt", "r", stdin);
    F(br, 0, sz) {
        int gap = 0;
        F(r, 0, sz) {
            int p = br;
            F(c, 0, sz) {
                a[br*sz+r][c*sz+p] = 1;
                (p += gap) %= sz;
            }
            ++gap;
        }
    }
    int n = 2000;
    printf("%d\n", n);
    F(i, 0, n) {
        F(j, 0, n) if (a[i][j]) putchar('1'); else putchar('0');
        puts("");
    }
    return 0;
}