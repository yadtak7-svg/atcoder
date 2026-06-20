#include <bits/stdc++.h>
using namespace std;

#define MAXT 1000010

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, d; cin >> n >> d;
    vector<long long> T(MAXT, 0);

    int maxT = 0;

    for(int i = 0; i < n; i++) {
        int s, t;
        cin >> s >> t;
        maxT = (maxT < t ? t : maxT);

        if(t - s < d) continue;

        T[s]++; T[t - d + 1]--;
    }

    long long ans = 0;
    for(int i = 1; i <= maxT; i++) {
        T[i] +=T[i - 1];

        if(T[i] >= 2) ans += T[i] * (T[i] - 1) / 2;
    }

    cout << ans << endl;
}