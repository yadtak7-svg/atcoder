#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<long long> A(n + 1);

    long long cur = 0;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];

        cur += A[i];

        if (cur <= k) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
            cur -= A[i];  
            A[i] = 0;     
        }

        cur -= A[max(0, i - m + 1)];
    }
}