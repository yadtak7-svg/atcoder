#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll n, k;
vector<ll> a, b, c;

int main (void) {
	cin >> n >> k;
	a.resize(n);
	b.resize(n);
	c.resize(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}

	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>> > que;

	vector<ll> ans(n, -1);
	ll sum = 0;
	ll t = 0;
	for (ll i = 0; i < n; i++) {
		t = max(t, a[i]);
		while (sum + c[i] > k) {
			pair<ll, ll> q = que.top(); que.pop();
			t = max(t, q.first);
			sum -= q.second;
		}

		ans[i] = t;
		que.push({t + b[i], c[i]});
		sum += c[i];
	}

	for (ll i = 0; i < n; i++) {
		cout << ans[i] << "\n";
	}
	
	return 0;
}
