#include <bits/stdc++.h>
using namespace std;
const int N = 1.5e4 + 5, V = 3.2e4 + 5;
struct star {
    int x, y;
};
star s[N];
int n, f[V], ans[N];
void Add(int i) {
    for (; i < V; i += i & -i)
        ++f[i];
}
int Query(int i) {
    int res = 0;

    for (; i; i -= i & -i)
        res += f[i];

    return res;
}
int main() {
    freopen("dcutes.in", "r", stdin);
    freopen("dcutes.out", "w", stdout);
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        ++x;
        ++ans[Query(x)];
        Add(x);
    }

    for (int i = 0; i < n; ++i)
        cout << ans[i] << endl;

    return 0;
}