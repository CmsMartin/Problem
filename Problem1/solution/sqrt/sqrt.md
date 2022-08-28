# CMS loves SQRT technology

## Algorithm1

考虑动态规划。

假设 $dp[i][j]$ 表示当 $p=i,k=j$ 时的答案。

方程显然可以写出来：

$$
dp_{i,j} = \left\{
    \begin{array}{lc}
	1 \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ i+a_i+n>n\\
   dp_{i+a_i+n,j}+1  \ \ \ \ \ \ \ otherwise
  \end{array}
\right.
$$

预处理时间复杂度 $O(nk)$，空间复杂度 $O(nk)$。

显然做不了。

## Algorithm2

考虑暴力，每次询问时间复杂度 $O(\frac{n}{k})$。

显然也做不了。

---

我们发现，Algorithm1 在 $k$ 比较小的时候可以 AC， Algorithm2 在
$k$ 比较大的时候可以 AC。

所以我们可以大胆结合，当 $k \le \sqrt n$ 时使用 Algorithm1，当 $k \ge \sqrt n$ 的时候使用 Algorithm2。

这样我们的时间和空间复杂度均变成了 $O(n \sqrt n)$， 可以 AC。

根据这两档的部分分，个人认为已经暗示的够明显了。

这种思想被称作 **根号分治**。

```cpp
#include <bits/stdc++.h>
using namespace std;

int N , Q , Num[100010] , NN;
int P , K;

int Dp[100010][350];

signed main() {
	freopen("sqrt.in", "r", stdin);
    freopen("sqrt.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	NN = sqrt(N);
	for (int i = 1; i <= N; i++) {
		cin >> Num[i];
	}

	for (int i = N; i >= 1; i--) {
		for (int j = 1; j <= NN; j++) {
			if (i + Num[i] + j > N) Dp[i][j] = 1;
			else Dp[i][j] = Dp[i + Num[i] + j][j] + 1;
		}
	}

	cin >> Q;
	while (Q--) {
		cin >> P >> K;
		if (K <= NN) {
			cout << Dp[P][K] << endl;
		}
		else {
			int res = 0;
			while (P <= N) {
				P = P + Num[P] + K;
				res++;
			}
			cout << res << endl;
		}
	}
	return 0;
}
```
