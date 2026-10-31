#include <bits/stdc++.h>
#include <atcoder/convolution>
#include <atcoder/modint>

using namespace std;
using mint = atcoder::modint998244353;
using vm = vector<mint>;

vector<mint> fact, ifact;
mint C(int n, int k) {
    if (k < 0 || k > n || n < 0) return 0;
    return fact[n] * ifact[k] * ifact[n - k];
}
vm binom(int k) {              
    vm r(k + 1);
    for (int i = 0; i <= k; i++) r[i] = C(k, i);
    return r;
}

int n;
vector<mint> w;   
vector<int> typ; 

struct Node { vm R; int a, b; };

Node solve(int l, int r) {
    if (r - l == 1) {
        Node nd;
        nd.R = {w[l], w[l]};               
        nd.a = typ[l];
        nd.b = typ[l] ? -1 : 1;
        return nd;
    }
    int mid = (l + r) / 2;
    Node A = solve(l, mid), B = solve(mid, r);
    int L1 = mid - l, L2 = r - mid;
    vm p1 = atcoder::convolution(A.R, binom(L2));
    vm p2 = atcoder::convolution(B.R, binom(A.b + L1));
    vm res(max(p1.size(), p2.size() + A.a));
    for (size_t i = 0; i < p1.size(); i++) res[i] += p1[i];
    for (size_t i = 0; i < p2.size(); i++) res[i + A.a] += p2[i];
    return {move(res), A.a + B.a, A.b + B.b};
}

int main() {
    cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &a[i], &b[i]);
    }

    int F = 5 * n + 10;
    fact.assign(F, 1); ifact.assign(F, 1);
    for (int i = 1; i < F; i++) fact[i] = fact[i - 1] * i;
    ifact[F - 1] = fact[F - 1].inv();
    for (int i = F - 1; i > 0; i--) ifact[i - 1] = ifact[i] * i;
    vector<mint> pw2(n + 1, 1);
    for (int i = 1; i <= n; i++) pw2[i] = pw2[i - 1] * 2;

    vector<pair<long long, int>> ev;
    for (int i = 0; i < n; i++) {
        ev.push_back({min(a[i], b[i]), 0});
        ev.push_back({max(a[i], b[i]), 1});
    }
    sort(ev.begin(), ev.end());
    int E = 2 * n;
    w.assign(E, 0); typ.assign(E, 0);
    int m = 0;
    long long prev = 0;
    for (int s = 0; s < E; s++) {
        w[s] = mint((ev[s].first - prev) % 998244353) * pw2[n - m];
        prev = ev[s].first;
        typ[s] = ev[s].second;
        m += typ[s] ? -1 : 1;
    }

    Node root = solve(0, E);

    vm inv(n + 1);
    for (int j = 0; j <= n; j++) {
        mint c = C(2 * n - 1 + j, j);
        inv[j] = (j & 1) ? -c : c;
    }
    vm P = atcoder::convolution(root.R, inv);
    P.resize(n + 1);

    mint s = 0;
    for (int k = 1; k <= n; k++) {
        s += P[k - 1];
        cout << s.val() << '\n';
    }
}