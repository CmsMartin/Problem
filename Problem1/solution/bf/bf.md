# CMS loves BF technology
---

这道题有一个很有意思的结论：$p[i]$ 是一个排列的时候，所有的点 $i$ 向 $p[i]$ 连边之后会形成若干个环，不会有环 + 链的形状出现。这个是显然的，如果出现 环 + 链 就会出现 $p[i]=p[j]$，而 $p$ 是一个排列，显然矛盾。

由于题目要求每一个点的度数均为 $1$，那么对于每一个偶环，确定一条边的状态就可以确定其他的所有边。这样我们就可以很简单的做这道题目了，但是时间复杂度为 $\Theta(2^{\frac{n}{2}})$, 不可以接受。

考虑优化，对于点数小于 $4$（必定点数等于 $2$）的环，我们可以直接决定出来哪条边是左括号，哪条边是右括号，这样就可以做到，$\Theta(2^{\frac{n}{4}})$, 可以承受。这个剪枝是非常强力的。

```cpp
#include <bits/stdc++.h>
using namespace std;

int N, P[110], num, Belong[110], Color[110], Size[110], Vis[110];
int Cnt[2];

bool Check() {
    Cnt[0] = Cnt[1] = 0;

    for (int i = 1; i <= N; i++) {
        Cnt[Vis[Belong[i]] ^ Color[i]]++;

        if (Cnt[0] > Cnt[1])
            return false;
    }

    if (Cnt[0] != Cnt[1])
        return false;

    return true;
}

void Dfs(int now) {
    if (now > num) {
        if (Check()) {
            for (int i = 1; i <= N; i++) {
                cout << (Vis[Belong[i]] ^ Color[i] ? '(' : ')');
            }

            exit(0);
        }

        return;
    }

    Vis[now] = true;
    Dfs(now + 1);

    if (Size[now] > 2) {
        Vis[now] = false;
        Dfs(now + 1);
    }
}

int main() {
    freopen("bf.in", "r", stdin);
    freopen("bf.out", "w", stdout);

    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> P[i];
    }

    for (int i = 1; i <= N; i++) {
        if (Belong[i] == 0) {
            Belong[i] = ++num;
            bool flag = false;

            for (int j = P[i]; j != i; j = P[j]) {
                flag ^= 1;
                Color[j] = flag;
                Belong[j] = num;
                Size[num]++;
            }

            Size[num]++;
        }
    }

    Dfs(1);
    return 0;
}
```