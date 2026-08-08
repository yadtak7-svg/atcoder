#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a, b; cin >> n >> a >> b;
    string S; cin >> S;
    for(int i = a; i < n - b; i++) cout << S[i];
    cout << "\n";
}