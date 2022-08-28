# CMS loves MATH technology
---

诈骗题。

易得答案为最大值 + 次大值 - 最小值 - 次小值。

我们将最大值和最小值看做一个区间，次大值和次小值看做一个区间。

接着分类讨论。

+ 区间不重合：答案为 $max + premax - premin - minmax$。

+ 一个区间完全被包含在另一个区间：无影响，答案同上。

+ 两区间交叉重叠：

  + 重叠部分分别为最小值、次小值或最大值、次大值，拆分一下区间你会发现还是原来的答案。

  + 重叠部分分别为最大值、次小值或次大值，最小值，将两个重叠值进行计算，外面的进行计算，答案还是不变。

```cpp
#include <bits/stdc++.h>
using namespace std;

namespace io {
const int SIZE = (1 << 21) + 1;
char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55];
int f, qr;
// getchar
#define gc() (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS++)) : *iS++)
// print the remaining part
inline void flush() {
    fwrite(obuf, 1, oS - obuf, stdout);
    oS = obuf;
}
// putchar
inline void putc(char x) {
    *oS++ = x;
    if (oS == oT) flush();
}
// input a signed integer
template <class I>
inline void read(I &x) {
    for (f = 1, c = gc(); c < '0' || c > '9'; c = gc())
        if (c == '-') f = -1;
    for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15);
    x *= f;
}
// print a signed integer
template <class I>
inline void print(I x) {
    if (!x) putc('0');
    if (x < 0) putc('-'), x = -x;
    while (x) qu[++qr] = x % 10 + '0', x /= 10;
    while (qr) putc(qu[qr--]);
}
struct Flusher_ {
    ~Flusher_() {
        flush();
    }
} io_flusher_;
}  // namespace io
using io ::print;
using io ::putc;
using io ::read;

int N, T;
int Num[100010];

int main() {
    freopen("math.in", "r", stdin);
    freopen("math.in", "w", stdout);
    read(T);
    while (T--) {
        read(N);
        for (int i = 1; i <= N; i++) read(Num[i]);
        sort(Num + 1, Num + 1 + N);
        print(Num[N] + Num[N - 1] - Num[1] - Num[2]);
        putc('\n');
    }
    return 0;
}
```