#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vector<int> A(n); 
    for(int i = 0; i < n; i++) A[i] = i + 1;

    int shift = 0;

    while(q--) {
        int t; cin >> t;
        if(t == 1) {
            int p, x; cin >> p >> x;
            A[(p - 1 + shift) % n] = x;
        }
        if(t == 2) {
            int p; cin >> p;
            cout << A[(p - 1 + shift) % n] << endl;
        }
        if(t == 3) {    
            int k; cin >> k;
            k %= n;
            shift = (shift + k) % n;
        }
    }
}