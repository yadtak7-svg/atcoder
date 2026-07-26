#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<string> S, T;
    int n, k , x;

    cin >> n >> k >> x;
    x--;
    int size = 1;
    for(int i = 0; i < k; i++) size *= n;
    T.resize(size);
    S.resize(n);
    for(int i = 0; i < n; i++) cin >> S[i];

    for(int i = 0; i < size; i++) {
        int z = i;
        for(int j = 0; j < k; j++) {
            T[i] = S[z % n] + T[i];
            z /= n;    
        }
    }
    sort(T.begin(), T.end());
    cout << T[x] << '\n';
}