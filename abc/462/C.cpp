#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<pair<int,int>> P(n);
    for(int i = 0; i < n; i++) {
        cin >> P[i].first >> P[i].second;
    }

    sort(P.begin(), P.end());

    int ans = 0;
    int min = P[0].second;
    for(int i = 0; i < n; i++) {
        int y = P[i].second;
        if(y <= min) ans++;
        min = (min > y ? y : min);
    }

    cout << ans << endl;
}