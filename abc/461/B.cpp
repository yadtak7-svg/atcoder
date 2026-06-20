#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> A(n), B(n);

    for(int i = 0; i < n; i++) {cin >> A[i], A[i]--; }
    for(int i = 0; i < n; i++) {cin >> B[i], B[i]--; }

    bool ok = true;
    for(int i = 0; i < n; i++) {
        if(B[A[i]] != i) ok = false;
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}