#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<char> C(n);
    vector<long long> A(n);
    long long cnt = 0;
    for(int i = 0; i < n; i++) {
        cin >> C[i] >> A[i];
        cnt += A[i];
        if(cnt > 100) {
            cout << "Too Long\n";
            return 0;
        }
    }    

    for(int i = 0; i < n; i++) {
        while(A[i]--) {
            cout << C[i];
        }
    }
    cout << '\n';
}