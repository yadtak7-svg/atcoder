#include <bits/stdc++.h>
using namespace std;

long long solve(int n, vector<long long> &A) {
    long long ans = 0;

    priority_queue<long long, vector<long long>> que;
    for(long long i = 0; i < n; i++) {
        if(i == 0) {
            que.push(A[i*2]);
        }
        else {
            que.push(A[i * 2 - 1]);
            que.push(A[i * 2]);
        }
        long long v = que.top();
        que.pop();
        
        ans += v;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;

    while(t--) {
        long long n;
        cin >> n;

        vector<long long> A(2 * n);
        for(int i = 0; i < 2 * n; i++) cin >> A[i];
        
        cout << solve(n, A) << endl;
    }
}