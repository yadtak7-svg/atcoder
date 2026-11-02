#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> A(n);
    for(int i = 0; i < m; i++) {
        cin >> A[i];
        A[i]--;    
    }

    int i = 0;
    int cnt = 0;
    int nxt = A[cnt];
    while(i < n) {
        cout << nxt - i << '\n';
        if(i == nxt) {
            cnt++;
            nxt = A[min(cnt, m - 1)];
        }
        i++;
    }
}