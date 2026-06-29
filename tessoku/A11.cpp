#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    
    vector<int> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];

    int l = 0, r = n - 1;
    while(l <= r) {
        int mid =(l + r) / 2;
        if(x < A[mid]) r = mid - 1;
        else if((x > A[mid])) l = mid + 1;
        else {
            cout << mid + 1 << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';

}