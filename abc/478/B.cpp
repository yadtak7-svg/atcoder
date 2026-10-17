#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, v; cin >> n >> v;
    vector<int> w(n);

    for(int i = 0; i < n; i++) cin >> w[i];


    int ans = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            if(j == i) continue;
            for(int k = 0; k < n; k++) {
                if(k == i || k == j) continue;
                int tmp = w[i] + w[j] + w[k];

                if(i + j + k + 3 <= v) ans = max(ans, tmp);
            }
        }
    }

    cout << ans << '\n';
}