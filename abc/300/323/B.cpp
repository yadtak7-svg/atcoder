#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<string> S(n);
    for(int i = 0; i < n; i++) {
        cin >> S[i];
    } 

    vector<pair<int, int>> A(n);
    for(int i = 0; i < n; i++) A[i] = {n, i};
    int cur = 1;
    for(int i = 0; i < n; i++) {
        for(int j = cur; j < n; j++) {
            if(S[i][j] == 'o') A[i].first--;
            else A[j].first--;
        }
        cur++;
    }

    sort(A.begin(), A.end());
    for(int i = 0; i < n; i++) cout << A[i].second + 1 << ' ';
    cout << '\n';

}