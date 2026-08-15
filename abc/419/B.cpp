#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q; cin >> q;
    vector<int> A(q, 1e9);
    vector<bool> used(q, false);
    for(int i = 0; i < q; i++) {
        int t; cin >> t;
        if(t == 1) {
            cin >> A[i];
        }
        if(t == 2) {
            int MIN = 1e9;
            int idx = 0;
            for(int j = 0; j < q; j++) {
                if(!used[j] && A[j] < MIN) {
                    MIN = A[j];
                    idx = j;
                }
            }
            used[idx] = true;
            cout << MIN << '\n';
        }
    }
}