#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x; cin >> n >> x;
    vector<int> A(n - 1);
    int mx = 0, mn = 1e9, sum = 0;
    for(int i = 0; i < n - 1; i++) {
        cin >> A[i];
        mx = max(mx, A[i]);
        mn = min(mn, A[i]);
        sum += A[i];
    }

    int need = x - (sum - mx - mn);
    int ans;
    if(need <= 0 || sum - mx >= x) ans = 0;
    else if(mn <= need && need <= mx)  ans = need;
    else if(sum - mn >= x) ans = mx;
    else ans = -1;

    cout << ans << '\n';
}