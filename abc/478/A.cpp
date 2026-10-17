#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> A(n, 0);
    int i = 0;
    while(m--) {
        A[i]++;
        i= (i + 1) % n;
    }

    for(int x : A) cout << x << '\n';
}