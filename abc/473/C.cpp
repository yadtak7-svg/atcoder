#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;
    vector<int> A(k, 0);
    for(int i = 0; i < n; i++) {
        int x; cin >> x; x--;
        A[x]++;
    }
    
    sort(A.begin(), A.end(), greater<int>());

    int MAX = A[0];
    int cnt = 0;
    while(cnt < n && A[cnt] >= MAX - 1) {
        cnt++;
    }

    cout << cnt << '\n';
}