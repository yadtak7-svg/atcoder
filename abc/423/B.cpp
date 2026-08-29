#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];

    int l = 0, r = n;
    for(int i = 0; i < n; i++) {
        if(A[i] == 0) l++;
        else break;
    }
    for(int i = n - 1; i >= 0; i--) {
        if(A[i] == 0) r--;
        else break;
    }

    int ans = max(0, r - l - 1);

    cout << ans << '\n';

}