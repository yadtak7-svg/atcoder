#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> A(n), B(n);
    vector<long long> ans(n, 1);
    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 0; i < n; i++) cin >> B[i];

    bool ok = false;
    for(int i = 0; i < n; i++) {
        if(ok) break;
        if(A[i] > B[i]) {
            ok = true;
            ans[i] = 1e18;
        }
    }

    if(!ok) {
        cout << "No\n";
        return 0;
    }

    cout << "Yes" << '\n';
    for(long long x : ans) {
        cout << x << ' ';
    }
    
}