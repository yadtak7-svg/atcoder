#include <bits/stdc++.h>
using namespace std;

int f(string s) {
    if(s == "Ocelot") return 1;
    else if(s == "Serval") return 2;
    else return 3;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, t; cin >> s >> t;
    int a = f(s), b = f(t);

    if(a >= b) cout << "Yes\n";
    else cout << "No\n";

}