#include <bits/stdc++.h>
using namespace std;

int n; 

vector<vector<int>> rot(vector<vector<int>> S) {
    vector<vector<int>> G(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            G[i][j] = S[n - 1 - j][i]; 
        }
    }
    return G;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int>> S, T;
    cin >> n;

    S.resize(n, vector<int>(n, 0));
    T.resize(n, vector<int>(n, 0));
    
    char c;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> c;
            if(c == '.') S[i][j] = 1;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> c;
            if(c == '.') T[i][j] = 1;
        }
    }

    vector<int> cnt(4, 0);

    int ans = 1e9;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(S[j][k] != T[j][k]) cnt[i]++;
            }
        }
        ans = min(ans, i + cnt[i]);
        S = rot(S);
    }

    cout << ans << endl;
}