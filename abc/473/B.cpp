#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> A(n);

    long long sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> A[i];
        sum += A[i];
    }

    sort(A.begin(), A.end());

    long long ans = sum;
    int i = 0;
    while(i < n) {
        int j = i;
        while(j < n && A[j] == A[i]) j++;

        int cnt = j - i;                   
        int pairs = cnt / 2;                 
        ans -= 2LL * A[i] * pairs;           
        i = j;
    }

    cout << ans << '\n';
}
