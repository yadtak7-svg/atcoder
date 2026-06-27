#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> A(n);
    long long ans = 0, sum = 0;
    vector<long long> psum(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> A[i];
        sum += A[i];
        if(i == 0) psum[i] = A[i];
        else psum[i] = psum[i - 1] + A[i];
    }

    for(int i = 0; i < n; i++) {
        ans += A[i] * (sum - psum[i]);
    }

    cout << ans << endl;
}