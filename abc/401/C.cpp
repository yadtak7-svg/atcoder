#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> A(n + 1, 0);
    for(int i = 0; i < k && i <= n; i++) A[i] = 1;

    int sum = k;
    for(int i = k; i <= n; i++) {
        A[i] = sum % mod;
        sum -= A[i - k];
        sum += A[i];
        
        if(sum < 0) sum += mod;
        if(sum >= mod) sum -= mod;
    }

    cout << A[n] << endl;


}