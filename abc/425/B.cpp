#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> A(n), P(n);
    vector<int> cnt(n + 1, 0);

    bool ok = true;

    for(int i = 0; i < n; i++) {
        cin >> A[i];
        if(A[i] != -1) {
            if(++cnt[A[i]] > 1) ok = false;
            P[i] = A[i];
        }
    }

    if(!ok) {
        cout << "No\n";
        return 0;
    }

    vector<int> need;
    for(int v = 1; v <= n; v++) {
        if(cnt[v] == 0) need.push_back(v);
    }

    vector<int> pos;
    for(int i = 0; i < n; i++) {
        if(A[i] == -1) pos.push_back(i);
    }

    if(need.size() != pos.size()) {
        cout << "No\n";
        return 0;
    }

    for(int i = 0; i < (int)need.size(); i++) {
        P[pos[i]] = need[i];
    }

    cout << "Yes\n";
    for(int x : P) cout << x << ' ';
    cout << '\n';
}
