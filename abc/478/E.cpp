#include <iostream>
#include <vector>
#include <ranges>
#include <atcoder/scc>

int main() {
    using namespace std;
    unsigned N, Q;
    cin >> N >> Q;
    atcoder::scc_graph scc(N);
    vector<pair<unsigned, unsigned>> lt;
    for (unsigned i{}; i < Q; ++i) {
        unsigned t, u, v;
        cin >> t >> u >> v;
        --u;
        --v;
        scc.add_edge(u, v);
        if (t) lt.emplace_back(u, v); // t = 1 の辺をまとめておく
    }

    vector<unsigned> ans(N);
    // 強連結成分のトポロジカル順序に従って番号を付ける
    for (const auto& [i, component] : scc.scc() | views::enumerate)
        for (const auto x : component)
            ans[x] = i + 1;

    // 矛盾が生じたら 
    for (const auto& [u, v] : lt)
        if (ans[u] == ans[v]) {
            cout << "No" << endl;
            return 0;
        }
    cout << "Yes" << endl;
    for (string delim{}; const auto a : ans) cout << a << " ";
    cout << endl;
    return 0;
}
