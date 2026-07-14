#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, l; cin >> n >> l;
    
    vector<long long> L(l, 0);
    int last = 0; L[0]++;
    for(int i = 0; i < n - 1; i++) {
        int x; cin >> x;
        last = (last + x) % l;
        L[last]++;
    }

    long long ans = 0;
    int c = l / 3;
    for(int i = 0; i < c; i++) {
        ans += L[i] * L[i + c] * L[i + 2 * c];
    }

    if(l % 3 != 0) ans = 0;

    cout <<  ans << endl;
}