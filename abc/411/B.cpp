#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> A(n); A[0] = 0;
    for(int i = 1; i < n; i++) {
        int a; cin >> a;
        A[i] = A[i - 1] + a;
    }

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            cout << A[j] - A[i] << ' ';
        }
        cout << '\n';
    }
}