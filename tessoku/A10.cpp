#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];

    vector<int> M(n), revM(n);
    
    for(int i = 0; i < n; i++) {
        if(i == 0) M[0] = A[0];
        else {
            M[i] = max(M[i - 1], A[i]);
        } 
    }
    for(int i = n - 1; i >= 0; i--) {
        if(i == n - 1) revM[n - 1] = A[n - 1];
        else {
            revM[i] = max(revM[i + 1], A[i]);
        } 
    }  
    int d; cin >> d;
    while(d--) {
        int l, r; cin >> l >> r;
        l--; r--;
        int ans = 0;
        if(0 < l) ans = max(ans, M[l - 1]);
        if(n - 1 > r) ans = max(ans, revM[r + 1]);
        cout << ans << '\n';
    }
}