#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long sum = 0;
    long long n;
    int m;

    cin >> n >> m;

    long long k = 1;

    for(int i = 0; i <= m; i++) {
        sum += k;
        if(sum > 1e9) {
            cout << "inf" << endl;
            return 0;
        }
        k *= n;
    }

    cout << sum << endl;
}