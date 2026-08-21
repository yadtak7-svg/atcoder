#include <bits/stdc++.h>
using namespace std;

long long f(long long x) {
    string s = to_string(x);
    reverse(s.begin(), s.end());
    return stoll(s);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long a, b; cin >> a >> b;
    vector<long long> ans(10);
    ans[0] = a; ans[1] = b;
    for(int i = 2; i < 10; i++) {
        long long tmp = ans[i - 1] + ans[i - 2];
        ans[i] = f(tmp);
    }

    cout << ans[9] << '\n';
}