#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long a, b; cin >> a >> b;
    if(a < b) swap(a, b);

    while(a != b) {
        a -= b;
        if(a < b) swap(a, b);
    }

    cout << a << endl;
}