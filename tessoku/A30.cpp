#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

vector<long long> fac, finv, inv;
int n, r; 

void comb_init() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < n + 10; i++){
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod%i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}

long long comb(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}

int main() {
    cin >> n >> r;
    fac.resize(n + 10);
    finv.resize(n + 10);
    inv.resize(n + 10);
    comb_init();
    cout << comb(n, r) << endl;
}
