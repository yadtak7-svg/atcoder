#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vector<pair<int,int>> A(n + 1);
    for(int i = 0; i <= n; i++) A[i] = {0, i};
    A[0] = {1e9, 0};
    while(q--) {
        int x; cin >> x;
        int ans;
        if(x != 0) A[x].first++, ans = x;
        else {
            vector<pair<int,int>> tmp = A;
            sort(tmp.begin(), tmp.end());
            ans = tmp[0].second;
            A[ans].first++;
        }

        cout << ans << ' ';
    }

    cout << endl;
}