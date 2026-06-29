#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;
    vector<int> A(n), B(n), C(n), D(n), AB(n * n), CD(n * n);
    
    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 0; i < n; i++) cin >> B[i];
    for(int i = 0; i < n; i++) cin >> C[i];
    for(int i = 0; i < n; i++) cin >> D[i];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            AB[i * n + j] = A[i] + B[j];
            CD[i * n + j] = C[i] + D[j]; 
        }
    }

    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());

    for(int i = 0; i < n * n; i++) {
        int l = 0, r = n * n - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            int tmp = AB[i] + CD[mid];
            if(tmp == k) {
                cout << "Yes" << '\n';
                return 0;
            }
            if(tmp < k) l = mid + 1;
            else r = mid - 1;
        }
    }
    cout << "No\n";
}