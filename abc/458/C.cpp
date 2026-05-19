#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string S;
    cin >> S;
    int len = S.size();

    long long ans = 0;
    for(long long i = 0; i < len; i++) {
        if(S[i] == 'C') {
            ans += min(i ,len - i - 1) + 1;
        }
    }

    cout << ans << endl;
}