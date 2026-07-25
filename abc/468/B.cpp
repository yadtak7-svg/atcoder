#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, d; 
    cin >> n >> d;

    vector<bool> A(n, true);
    string S; 
    cin >> S;

    for(int i = 0; i < n; i++) {
        if(S[i] == 'G') {
            for(int j = max(0, i - d); j <= min(n - 1, i + d); j++) {
                A[j] = false;
            }
        }
    }

    int ans = 0;
    for(bool x : A) if(x) ans++;
    cout << ans << '\n';
}
