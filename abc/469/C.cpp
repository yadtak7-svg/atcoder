#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    string S; cin >> S;
    vector<int> pos;
    for(int i = 0; i < n; i++) 
        if(S[i] == 'x') pos.push_back(i + 1);
  
    for(int k=1;k<=n;k++) {
        if(k <= pos.size())
            cout << pos[k - 1] << '\n';
    else cout << n << '\n';
    }
}