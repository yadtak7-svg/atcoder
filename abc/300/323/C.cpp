#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> A(m);
    vector<string> S(n);

    for(int i = 0; i < m; i++) cin >> A[i];
    for(int i = 0; i < n; i++) cin >> S[i];

    vector<int> sc(n, 0);
    for(int i = 0; i < n; i++) {
        sc[i] += (i + 1);
        for(int j = 0; j < m; j++) {
            if(S[i][j] == 'o') sc[i] += A[j];
        }
    }

    int mx = 0; 
    for(int i = 0; i < n; i++) mx = max(mx, sc[i]);

    vector<pair<int, int>> B(m);
    for(int i = 0; i < m; i++) B[i] = {A[i], i};
    sort(B.begin(), B.end());

    for(int i = 0; i < n; i++) {
        int need = mx - sc[i];
        int cnt = 0, j = m;
        while(need > 0) {
            j--;
            if(S[i][B[j].second] == 'o') continue;
            else {
                need -= B[j].first;
                cnt++;
            }
        }
        cout << cnt << '\n';
    }

}