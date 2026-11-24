#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> A(n), B(n);
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> B[i];
    }

    int miss = 0;
    int i = 0, j = 0;
    while(i < n || j < n) {
        if(i < n && j < n && A[i] == B[j]) {
            i++;
            j++;
        }
        else if(i < n && (j == n - 1 || A[i] != B[j])) {
            miss++;
            i++;
        }
        else {
            miss++;
            j++;
        }
    }

    if(miss <= 1) {
        cout << "Yes" << '\n';
    } 
    else {
        cout << "No\n";
    }

}