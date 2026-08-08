#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> A(n), B(m);
    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 0; i < m; i++) cin >> B[i];

    vector<bool> del(n, false), used(m, false);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(A[i] == B[j] && !used[j]) {
                del[i] = true, used[j] = true;
                break;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(!del[i]) cout << A[i] << " ";
    }
    cout << "\n";

}