#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string S = "HelloWorld";

    int x;
    cin >> x;
    x--;
    
    for(int i = 0; i < S.size(); i++) {
        if(i != x) cout << S[i];
    }
    cout << endl;
}