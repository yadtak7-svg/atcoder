#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k; cin >> n >> k;

    long long ans = 0;

    for (int i = 1; i <= n; i++) {
        int j_min = max(1, k - i - n);
        int j_max = min(n, k - i - 1);

        if (j_min <= j_max)
            ans += (j_max - j_min + 1);
    }


    cout << ans << endl;
}