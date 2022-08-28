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