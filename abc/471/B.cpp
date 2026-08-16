#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N; cin >> N;

    vector<string> s(N);
    for (int i = 0; i < N; i++) cin >> s[i];

    set<string> kinds;
    for (auto &x : s) {
        string t = x;
        for (auto &c : t) c = tolower(c);
        kinds.insert(t);
    }

    unordered_map<string,int> cnt;
    for (auto &x : s) {
        string t = x;
        for (auto &c : t) c = tolower(c);
        cnt[t]++;
    }

    int ans = 0;
    for (auto &k : kinds) {
        ans = max(ans, cnt[k]);
    }

    cout << ans << endl;
}
