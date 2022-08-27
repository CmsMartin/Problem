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