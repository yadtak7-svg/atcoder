#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];

    int win = 0;
    for(int x : A) win ^= x;

    if(win) cout << "First\n";
    else cout << "Second\n";  
}