#include <bits/stdc++.h>
using namespace std;

long long f(int a) {
    long long res = 0;
    while(a > 0) {
        res += a%10;
        a /= 10;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<long long> A(n + 1); 
    A[0] = 1;
    for(int i = 1; i <= n; i++) {
        if(i == 1) {
            A[1] = 1;
            continue;
        }
        A[i] = A[i - 1] + f(A[i - 1]);
    }

    cout << A[n] << '\n';
}