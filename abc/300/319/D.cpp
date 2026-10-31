#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<long long> A(n);
    long long sum = 0;
    long long MAX = 0;
    for(int i = 0; i < n; i++) {
        long long a; cin >> a; a++;
        A[i] = a;
        sum += a;
        MAX = max(MAX, a - 1);
    }

    long long l = MAX, r = sum + 1;
    while(l < r) {
        long long mid = (l + r) / 2;

        long long cur = 0, tmp = 1;
        for(int i = 0; i < n; i++) {
            if(cur == 0) {
                cur = A[i] - 1;
            }
            else if(cur + A[i] <= mid) {
                cur += A[i];
            }
            else {
                cur = A[i] - 1;
                tmp++;
            }
        }

        if(tmp > m) l = mid + 1;
        else r = mid;
    }

    cout << l << '\n';
    

}