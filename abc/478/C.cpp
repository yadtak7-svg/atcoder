#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;
    vector<int> A(n), B(n);
    for(int i = 0; i < n; i++) cin >> A[i];

    B = A;
    sort(A.begin(), A.end());

    int l = -1, r;
    for(int i = 0; i < n; i++) {
        if(A[i] != B[i]) {
            l = i;
            break;
        }
    }
    for(int i = n - 1; i >= 0; i--) {
        if(A[i] != B[i]) {
            r = i;
            break;
        }
    }

    if(l == -1 || r - l + 1 <= k) {
        cout << "Yes\n";
    }
    else cout << "No\n";

}