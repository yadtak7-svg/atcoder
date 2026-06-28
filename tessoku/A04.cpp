#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    string S;
    while(n != 0) {
        if(n % 2 == 1) S.push_back('1');
        else S.push_back('0');
        n >>= 1;
    }
    int len = S.size();
    while(len++ < 10) S.push_back('0');
    reverse(S.begin(), S.end());
    cout << S;
}