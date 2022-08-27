#include <bits/stdc++.h>
using namespace std;

int N, P[110], num, Belong[110], Color[110], Size[110], Vis[110];
int Cnt[2];

bool Check() {
    Cnt[0] = Cnt[1] = 0;
    for(int i = 1; i <= N; i++) {
        Cnt[Vis[Belong[i]] ^ Color[i]]++;
        if(Cnt[0] > Cnt[1]) return false;
    }
    if(Cnt[0] != Cnt[1]) return false;
    return true;
}

void Dfs(int now) {
    if(now > num) {
        if(Check()) {
            for(int i = 1; i <= N; i++) {
                cout << (Vis[Belong[i]] ^ Color[i] ? '(' : ')');
            }
            exit(0);
        }
        return;
    }
    Vis[now] = true;
    Dfs(now + 1);
    Vis[now] = false;
    Dfs(now + 1);
}

int main() {
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
        }
    }

    Dfs(1);
    return 0;
}