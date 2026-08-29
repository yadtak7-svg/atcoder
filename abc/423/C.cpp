#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, c; cin >> n >> c; c--;
    vector<int> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];

    int l = 0, r = n;
    int ans = 0;
    for(int i = l; i < r; i++) {
        if(A[i] == 1) ans++;
    }

    ans += r - l + 1;
    
    cout << ans << '\n';

}