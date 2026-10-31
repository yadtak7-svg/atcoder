#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<string> S(5);
    for(int i = 0; i < 5; i++) {
        cin >> S[i];
    }
    int ans = 5;
    int tmp1 = 0, tmp2 = 0;
    for(int i = 0; i < 5; i++) {
        tmp1 = 0, tmp2 = 0;
        for(int j = 0; j < 5; j++) {
            if(S[i][j] == 'o') tmp1++;
            if(S[j][i] == 'o') tmp2++;
        }
        ans = min({ans,5-tmp1,5-tmp2});
    }

    tmp1 = 0, tmp2 = 0;
    for(int i = 0; i < 5; i++) {
        if(S[i][i] == 'o') tmp1++;
        if(S[4-i][4-i] == 'o') tmp2++;

    }

    ans = min({ans,5-tmp1,5-tmp2});  
    cout << ans << '\n';
}