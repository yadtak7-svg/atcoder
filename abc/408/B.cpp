#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> A(n), ans;
    for(int i = 0; i < n; i++) cin >> A[i];

    sort(A.begin(), A.end());

    int prev = A[0];
    int cnt = 1; 
    ans.push_back(A[0]);
    for(int i = 1; i < n; i++) {
        if(A[i] != prev) {ans.push_back(A[i]); cnt++; }         
        prev = A[i];
    }

    cout << cnt << endl;
    for(int x : ans) cout << x << ' ';
    cout << endl;
}