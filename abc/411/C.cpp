#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;
    int x, s = 0;
    vector<int> A(n + 1);
    for(int i = 0; i < q; i++) {
        cin >> x;
        s += (1-A[x-1])-A[x-1];
		s += (1-A[x])-A[x];
		A[x-1] = 1-A[x-1];
		A[x] = 1-A[x];
		cout << (s/2) << '\n';
    } 
}