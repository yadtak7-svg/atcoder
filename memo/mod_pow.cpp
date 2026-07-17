#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;

long long mod_pow(long long a, long long b) {
    long long cur = a % mod, res = 1;
    while (b > 0) {
        if (b & 1) 
            res = res * cur % mod;
        cur = cur * cur % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    long long a, b; cin >> a >> b;
    cout << mod_pow(a, b) << endl;
}