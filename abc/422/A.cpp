#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string S; cin >> S;
    int i, j; 
    i = S[0] - '0'; j = S[2] - '0';

    if(j == 8) i++, j = 1;
    else j++;

    cout << char(i + '0') << '-' << char(j + '0') << '\n';
}