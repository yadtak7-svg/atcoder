#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;


    vector<set<int>> log(n);
    vector<bool> all(n, false);

    while(q--) {
        int t;
        cin >> t;

        if(t == 1) {
            int x, y; cin >> x >> y;
            x--;y--;
            log[x].insert(y);
        }

        if(t == 2) {
            int x; cin >> x; x--;
            all[x] = true;
        }

        if(t == 3) {
            int x, y; cin >> x >> y;
            x--; y--;
            if(all[x] || log[x].find(y) != log[x].end()) {
                cout << "Yes" << endl;
            }
            else cout << "No" << endl;
        }
    }
}