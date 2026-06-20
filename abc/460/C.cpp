#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> A(n);
    vector<int> B(m);

    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 0; i < m; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    long long ans = 0;

    int i = 0, j = 0;
    while(i < n && j < m) {
        if(B[j] <= 2LL * A[i]) {
            ans++;
            i++;
            j++;
        }
        else {
            i++;
        }
    }

    cout << ans << endl;
}