#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string S; cin >> S;
    int n = S.size();
    char T[n]; 
    bool flag = true;
    for(int i = 0; i < n; i++) {
        if(S[i] == '#') {
            T[i] = '#';
            flag = true;
        }
        else {
            if(flag) {
                flag = false;
                T[i] = 'o';
            }
            else T[i] = '.';
        }
    }
    for(char c : T) cout << c;
    cout << "\n";
}