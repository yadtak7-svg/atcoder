#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    unordered_set<string> seen;
    vector<string> S(n);
    for(int i = 0; i < n; i++) cin >> S[i];
    
    int ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            
            if(i == j) continue;
            string nxt = S[i] + S[j];
            
            if (!seen.count(nxt)) {
                seen.insert(nxt);
                ans++;
            }
        }
    }

    cout << ans << '\n';
}