#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<char> a(n), b(n);
    bool ok = false; 
    
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    for(int i = 0; i < n; i++) 
        cin >> b[i];

    for(int i = 0; i < n; i++) 
        if(a[i] == 'o' && b[i] == 'o') ok = true;
    
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}