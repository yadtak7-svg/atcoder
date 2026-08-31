#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k; cin >> n >> m >> k;
    vector<int> cnt(n, 0);
    vector<int> ans;
    for(int i = 0; i < k; i++) {
        int j, t; cin >> j >> t;
        j--;
        cnt[j]++;
        if(cnt[j] == m) ans.push_back(j + 1);
    }

    for(int x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
}