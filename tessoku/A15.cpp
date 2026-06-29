#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> A(n);
    
    for(int i = 0; i < n; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }

    sort(A.begin(), A.end());
    int cur = A[0].first;
    int cnt = 1;
    for(int i = 0; i < n; i++) {
        if(A[i].first != cur) {
            cnt++;
            cur = A[i].first;
        }
        A[i].first = cnt;
    }
    vector<int> ans(n);
    for(int i = 0; i < n; i++) ans[A[i].second] = A[i].first;
    for(int x : ans) cout << x << " ";
    cout << '\n';
}