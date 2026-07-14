#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int ans = 0;
    int k;
    vector<int> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];
    cin >> k;

    for(int x : A) {
        if(x - k >= 0) ans++;
    }

    cout << ans << endl;
}