#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string S;
    cin >> S;

    int e = 0, w = 0;
    for(char c : S) {
        if(c == 'E') e++;
        else w++;
    }

    if(e > w) cout << "East" << endl;
    else cout << "West" << endl;
}