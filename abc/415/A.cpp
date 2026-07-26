#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];
    int x; cin >> x;
    for(int t : A) 
        if(t == x) {
            cout << "Yes\n";
            return 0;
        }
    
    cout << "No\n";
}