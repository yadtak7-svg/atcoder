#include <bits/stdc++.h>
using namespace std;

int n; 

int LIS(const vector<int> &A) {
    vector<int> dp(n, 1e9);
    for(int i = 0; i < n; ++i) {
        auto it = lower_bound(dp.begin(), dp.end(), A[i]);

        *it = A[i];
    }
    return lower_bound(dp.begin(), dp.end(), 1e9) - dp.begin();
}   

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];

    cout << LIS(A) << endl;
}