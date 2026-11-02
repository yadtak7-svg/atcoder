#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;

int op(int a, int  b) { return min(a, b); }
int inf() { return 1 << 30; }
int jud;
bool f(int x) { return x > jud; }

int main() {
	
    int n, m; cin >> n >> m;

	vector<int> a(n);
	atcoder::segtree<int, op, inf> seg(a);
	vector<long long> ans(n);
	
    for(int i = 0; i < m; i++) {
		int t, w, s;
		cin >> t >> w >> s;
		jud = t;
		int idx = seg.max_right(0, f);
		if (idx == n) continue;
		ans[idx] += w;
		seg.set(idx, t + s);
	}
	
    for (long long i : ans) cout << i << '\n';
}
