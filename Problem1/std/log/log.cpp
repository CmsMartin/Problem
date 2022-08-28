#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int Fa[10010][1010];

struct _ {
    int u, v, w, id;
} Edge[300010];
int Ans[300010];

int Find(int x, int p) {
    return Fa[p][x] == x ? x : Fa[p][x] = Find(Fa[p][x], p);
}

int main() {
    freopen("log.in", "r", stdin);
    freopen("log.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;

    for (int i = 1; i <= M; i++) {
        cin >> Edge[i].u >> Edge[i].v >> Edge[i].w;
        Edge[i].id = i;
    }

    sort(Edge + 1, Edge + 1 + M, [](_ a, _ b) {
        return a.w > b.w;
    });

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            Fa[j][i] = i;
        }
    }

    for (int i = 1, u, v; i <= M; i++) {
        tie(u, v) = make_pair(Edge[i].u, Edge[i].v);
        int l = 1, r = K, mid, p = 0;
        while (l <= r) {
            mid = l + r >> 1;
            if (Find(u, mid) != Find(v, mid)) {
                p = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (p) {
            Ans[Edge[i].id] = p;
            Fa[p][Find(u, p)] = Find(v, p);
        }
    }

    for (int i = 1; i <= M; i++) {
        cout << Ans[i] << endl;
    }
    return 0;
}