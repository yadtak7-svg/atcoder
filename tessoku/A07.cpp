#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int d, n;
    cin >> d >> n;
    vector<int> sum(d + 1, 0);
    
    for(int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        l--; r--;
        sum[l]++; sum[r+1]--;
    }

    for(int i = 1; i < d; i++) {
        sum[i] += sum[i - 1]; 
    }

    for(int i = 0; i < d; i++) {
        cout << sum[i] << '\n';
    }
}