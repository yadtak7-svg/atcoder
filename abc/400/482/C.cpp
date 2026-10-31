#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w; cin >> h >> w;
    int n, q; cin >> n >> q;

    vector<int> row, col;
    for(int i = 0; i < n; i++)  {
        int r, c; cin >> r >> c;
        row.push_back(r);
        col.push_back(c);    
    } 
    sort(row.begin(), row.end());
    sort(col.begin(), col.end());

    while(q--) {    
        int t, l, r; cin >> t >> l >> r;
        vector<int>& v = (t == 1 ? row : col);

        int cnt = upper_bound(v.begin(), v.end(), r)
                - lower_bound(v.begin(), v.end(), l);

        cout << cnt << '\n';
    }

}