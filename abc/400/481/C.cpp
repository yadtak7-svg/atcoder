#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    map<string, int> mp;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if (mp.count(s) == 0) {
            mp[s] = ++cnt;
        }

        cout << mp[s] << '\n';
    }

}