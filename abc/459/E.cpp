#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using mint = modint998244353;

vector<vector<int>> G;
vector<long long> C, D;

vector<mint> finv;

mint ans = 1;

void init_comb(int n) {

    vector<mint> fact(n + 1);
    finv.resize(n + 1);

    fact[0] = 1;

    for(int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i;
    }

    finv[n] = fact[n].inv();

    for(int i = n; i >= 1; i--) {
        finv[i - 1] = finv[i] * i;
    }
}

mint Cmb(long long n, int r) {

    if(r < 0 || r > n) return 0;

    mint res = 1;

    for(int i = 0; i < r; i++) {
        res *= (n - i);
    }

    res *= finv[r];

    return res;
}

long long dfs(int v) {

    long long free_candy = C[v];

    for(int nv : G[v]) {
        free_candy += dfs(nv);
    }

    if(free_candy < D[v]) {
        cout << 0 << '\n';
        exit(0);
    }

    ans *= Cmb(free_candy, D[v]);

    return free_candy - D[v];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    G.resize(N);
    C.resize(N);
    D.resize(N);

    for(int v = 1; v < N; v++) {
        int p;
        cin >> p;
        --p;

        G[p].push_back(v);
    }

    int sumD = 0;

    for(int i = 0; i < N; i++) {
        cin >> C[i];
    }

    for(int i = 0; i < N; i++) {
        cin >> D[i];
        sumD += D[i];
    }

    init_comb(sumD);

    dfs(0);

    cout << ans.val() << '\n';
}