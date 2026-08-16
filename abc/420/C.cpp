#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vector<long long> A(n), B(n);

    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 0; i < n; i++) cin >> B[i];

    long long res = 0;
    for(int i = 0; i < n; i++)  res += min(A[i], B[i]);

    while(q--) {
        char c; int x; long long v;
        cin >> c >> x >> v; x--;
        res -= min(A[x], B[x]);
        if(c == 'A') A[x] = v;
        else B[x] = v;
        res += min(A[x], B[x]);
        cout << res << '\n';
    }

}