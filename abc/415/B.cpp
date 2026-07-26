#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string S;
    vector<int> ans;
    cin >> S;
    for(int i = 0; i < S.size(); i++)  
        if(S[i] == '#') ans.push_back(i + 1);
    
    for(int i = 0; i < ans.size(); i += 2) {
        cout << ans[i] << ',' << ans[i + 1] << '\n';
    }  
}