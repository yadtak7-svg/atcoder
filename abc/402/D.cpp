#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, m;
    cin >> n >> m;

    long long ans = 0;

    vector<long long> dir(n + 10);
    for(long long i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        int d = a + b;
        if(d > n) d -= n;
        ans += dir[d];
        dir[d]++;
    } 

    long long total = m * (m - 1) / 2;
    cout << total - ans << endl;
}


