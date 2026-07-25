#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> A(n);
    int ans = 0;
    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 1; i < n - 1; i++) if(A[i - 1] < A[i] && A[i] > A[i + 1]) ans++;
    cout << ans << "\n";
}