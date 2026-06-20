#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    while(q--) {
        string S;
        cin >> S;

        int n = S.size();

        vector<pair<int,char>> cnt(26);

        for(int i = 0; i < 26; i++) {
            cnt[i] = {0, char('a' + i)};
        }

        int mx = 0;

        for(char c : S) {
            cnt[c - 'a'].first++;
            mx = max(mx, cnt[c - 'a'].first);
        }

        if(mx > (n + 1) / 2) {
            cout << "No\n";
            continue;
        }

        sort(cnt.begin(), cnt.end(),
            [](const pair<int,char>& a,
               const pair<int,char>& b) {
                return a.first > b.first;
            });

        string ans(n, ' ');

        int cur = 0;

        for(int i = 0; i < n; i += 2) {
            while(cur < 26 && cnt[cur].first == 0) cur++;

            ans[i] = cnt[cur].second;
            cnt[cur].first--;
        }

        for(int i = 1; i < n; i += 2) {
            while(cur < 26 && cnt[cur].first == 0) cur++;

            ans[i] = cnt[cur].second;
            cnt[cur].first--;
        }

        cout << "Yes\n";
        cout << ans << '\n';
    }
}