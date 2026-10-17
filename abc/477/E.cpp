#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vector<long long> A(n);
    vector<pair<long long, int>> B(n);
    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 0; i < n; i++) {
        cin >> B[i].first;
        B[i].second = i;
    } 
    
    vector<long long> P(n + 1); P[0] = 0;
    for(int i = 1; i <= n; i++) {
        P[i] = P[i - 1] + A[i - 1];
    }

    vector<long long> D(n);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    
    for (int i = 0; i < n; i++) {
        D[i] = B[i].first;
        pq.push({D[i], B[i].second});
    }

    while (!pq.empty()) {
        auto [l, i] = pq.top();
        pq.pop();

        if (l != D[i]) continue;

        int nxt = (i + 1) % n;
        if (D[nxt] > l + A[i]) {
            D[nxt] = l + A[i];
            pq.push({D[nxt], nxt});
        }

        int prv = (i - 1 + n) % n;
        if (D[prv] > l + A[prv]) {
            D[prv] = l + A[prv];
            pq.push({D[prv], prv});
        }
    }

    while(q--) {
        int u, v; cin >> u >> v;
        if (v == n + 1) {          
            cout << D[u - 1] << '\n';
            continue;
        }
        u--; v--;
        long long a = P[v] - P[u];
        long long b = P[n] - a;
        long long c = D[u] + D[v];

        long long ans = min({a, b, c});

        cout << ans << '\n';
    }    
    
}