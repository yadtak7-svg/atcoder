#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> P(n+1), A(n+1), B(n+1);
    vector<long long> S(n+1);
    for(int i = 1; i <= n; i++){
        cin >> P[i] >> A[i] >> B[i];
        S[i] = S[i-1] + B[i];
    }
    vector<vector<int> >dp(n+2, vector<int>(1001));
    for(int x = 0; x <= 1000; x++) dp[n + 1][x] = x;
    for(int i = n; i >= 1; i--){
        for(int x = 0; x <= 1000; x++){
            int y;
            if(x <= P[i]) y = x + A[i];
            else y = max(0, x - B[i]);
            dp[i][x] = dp[i + 1][y];
        }
    }
    
    int q; cin>>q;
    while(q--){
        long long x; cin>>x;
        int pos=lower_bound(S.begin(), S.end(), x - 500) - S.begin();
        if(pos>n) cout << x - S[n] << '\n';
        else cout << dp[pos + 1][x - S[pos]] << '\n';
    }
}