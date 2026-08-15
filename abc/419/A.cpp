#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string S; cin >> S;
    if(S == "red") cout << "SSS\n";
    else if(S == "blue") cout << "FFF\n";
    else if(S == "green") cout << "MMM\n";
    else cout << "Unknown\n"; 
}